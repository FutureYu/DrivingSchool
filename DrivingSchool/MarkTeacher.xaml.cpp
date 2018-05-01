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
		String^ tchID = ref new String(std::to_wstring(wcstol(previousOperation.get()->Data(), NULL, 10) / 10).c_str());
		TeacherBlock->Text = tchID;
		TipBlock->Text = "请评价您的编号为" + tchID + "的教练！";
	}).then([&]() {
		GetHistory();
	});
}

void DrivingSchool::MarkTeacher::ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	long history = wcstol(HistoryBlock->Text->Data(), NULL, 10);
	long avgScore = wcstol(AvgScoreBlock->Text->Data(), NULL, 10);
	long score = (RatingControl->Value)*10;
	long newScore = (avgScore * history + score) / (history + 1);
	FileWR::FileWrite(TeacherBlock->Text + ".sco", ref new String(std::to_wstring(newScore).c_str()));
	FileWR::FileWrite(TeacherBlock->Text + ".his", ref new String(std::to_wstring(++history).c_str()));
	FileWR::FileWrite(IDBlock->Text + ".tch", "0");
	MessageDialog msg("评价成功，感谢您的支持！", "评价成功");
	msg.ShowAsync();
	ConfirmBtn->IsEnabled = false;
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
		TipBlock->Text = "评价失败！请先预约教练！";
		ConfirmBtn->IsEnabled = false;
		return;
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
		long state = wcstol(previousOperation.get()->Data(), NULL, 10);
		if (state != 5 && state != 9)
		{
			TipBlock->Text = "评价失败，您可能未预约教练或未完成考试！";
			ConfirmBtn->IsEnabled = false;
			return;
		}
	});
}

void DrivingSchool::MarkTeacher::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}
