//
// MarkTeacher.xaml.cpp
// MarkTeacher 类的实现
//

#include "pch.h"
#include "MarkTeacher.xaml.h"

using namespace DrivingSchool;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// https://go.microsoft.com/fwlink/?LinkId=234238 上介绍了“空白页”项模板

MarkTeacher::MarkTeacher()
{
	InitializeComponent();
	// 异步任务链：读取id-> （读取老师->（读取历史评价人数->（读取平均分）））
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync("ID.id"))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		IDBlock->Text = previousOperation.get();
	}).then([&]()
	{
		GetTeacher();
	});
}

// 获取教练编号
void DrivingSchool::MarkTeacher::GetTeacher()
{
	String^ path = IDBlock->Text + ".tch";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		TeacherBlock->Text = previousOperation.get();
	}).then([&]() {
		GetHistory();
	});
}

void DrivingSchool::MarkTeacher::ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	long state = wcstol(ProgressNumberBlock->Text->Data(), NULL, 10);
	long history = wcstol(HistoryBlock->Text->Data(), NULL, 10);
	long avgScore = wcstol(AvgScoreBlock->Text->Data(), NULL, 10);
	long score = wcstol(ScoreBox->Text->Data(), NULL, 10);
	if (state != 5 && state != 9)
	{
		MessageDialog msg("评价失败，您可能未预约教练或未完成考试！", "评价失败");
		msg.ShowAsync(); return;
	}
	if (score > 100 || score < 0)
	{
		MessageDialog msg("分数范围错误！", "评价失败");
		msg.ShowAsync();
		ScoreBox->Text = "";
		return;
	}
	long newScore = (avgScore * history + score) / (history + 1);
	FileWR::FileWrite(TeacherBlock->Text + ".sco", ref new String(std::to_wstring(newScore).c_str()));
	FileWR::FileWrite(TeacherBlock->Text + ".his", ref new String(std::to_wstring(++history).c_str()));
	FileWR::FileWrite(IDBlock->Text + ".tch", "0");
	MessageDialog msg("评价成功，感谢您的支持！", "评价成功");
	msg.ShowAsync();
	ConfirmBtn->IsEnabled = false;
}


void DrivingSchool::MarkTeacher::ResetBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ScoreBox->Text = "";
}

// 获取教练编号
void DrivingSchool::MarkTeacher::GetScore()
{
	String^ path = TeacherBlock->Text + ".sco";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		AvgScoreBlock->Text = previousOperation.get();
	}).then([&]()
	{
		GetProgress();
	});
}

void DrivingSchool::MarkTeacher::GetHistory()
{
	if (TeacherBlock->Text == "0")
	{
		MessageDialog msg("请先预约教练！", "评价失败");
		ConfirmBtn->IsEnabled = false;
		msg.ShowAsync(); return;
	}
	else
	{
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		concurrency::create_task(storageFolder->GetFileAsync(TeacherBlock->Text + ".his"))
			.then([&](StorageFile^ file)
		{
			return FileIO::ReadTextAsync(file);
		}).then([&](concurrency::task<String^> previousOperation) {
			HistoryBlock->Text = previousOperation.get();
		}).then([&]()
		{
			GetScore();
		});

	}
}

void DrivingSchool::MarkTeacher::GetProgress()
{
	String^ path = IDBlock->Text + ".sta";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		ProgressNumberBlock->Text = previousOperation.get();
	});
}