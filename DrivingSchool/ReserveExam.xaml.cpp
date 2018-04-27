//
// ReserveExam.xaml.cpp
// ReserveExam 类的实现
//

#include "pch.h"
#include "ReserveExam.xaml.h"

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


ReserveExam::ReserveExam()
{
	InitializeComponent();

	// 读取ID，考试编号，进度编号
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync("ID.id"))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		IDBlock->Text = previousOperation.get();
	}).then([&]()
	{
		GetExamId();
	}).then([&]()
	{
		GetProgress();
	});
}

// 查询学习进度 
void DrivingSchool::ReserveExam::SearchBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	long progress = wcstol(ProgressNumberBlock->Text->Data(), NULL, 10);
	switch (progress)
	{
	case 0:
		ProgressBlock->Text = "您当前正在学习科目一，将为您预约科目一考试"; break;
	case 1:
		ProgressBlock->Text = "您已预约科目一考试，请积极准备考试"; break;
	case 2:
		ProgressBlock->Text = "您已通过科目一考试，请先预约科目二教练"; break;
	case 3:
		ProgressBlock->Text = "您当前正在学习科目二，将为您预约科目二考试"; break;
	case 4:
		ProgressBlock->Text = "您已预约科目二考试，请积极准备考试"; break;
	case 5:
		ProgressBlock->Text = "您已通过科目二考试，请先预约科目三教练"; break;
	case 6:
		ProgressBlock->Text = "您当前正在学习科目三，将为您预约科目三考试"; break;
	case 7:
		ProgressBlock->Text = "您已预约科目三考试，请积极准备考试"; break;
	case 8:
		ProgressBlock->Text = "您当前正在学习科目四，将为您预约科目四考试"; break;
	case 9:
		ProgressBlock->Text = "您已预约科目四考试，请积极准备考试"; break;
	case 10:
		ProgressBlock->Text = "恭喜您已通过考试！请耐心等待领取驾照"; break;
	}
}

// 获取学习进度 
void DrivingSchool::ReserveExam::GetProgress()
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

// 获取考试编号
void DrivingSchool::ReserveExam::GetExamId()
{
	String^ path = IDBlock->Text + ".exm";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		ExamBlock->Text = previousOperation.get();
	});
}

// 预约考试 异步任务链：判断可否预约，
void DrivingSchool::ReserveExam::ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	long progress = wcstol(ProgressNumberBlock->Text->Data(), NULL, 10);
	switch (progress)
	{
	case 1:
	{
		MessageDialog msg("您已预约科目一考试！", "预约失败");
		msg.ShowAsync(); return;
	}
	case 2:
	{
		MessageDialog msg("请先预约科目二教练！", "预约失败");
		msg.ShowAsync(); return;
	}
	case 4:
	{
		MessageDialog msg("您已预约科目二考试！", "预约失败");
		msg.ShowAsync(); return;
	}
	case 5:
	{
		MessageDialog msg("请先预约科目三教练！", "预约失败");
		msg.ShowAsync(); return;
	}
	case 7:
	{
		MessageDialog msg("您已预约科目三考试！", "预约失败");
		msg.ShowAsync(); return;
	}
	case 9:
	{
		MessageDialog msg("您已预约科目四考试！", "预约失败");
		msg.ShowAsync(); return;
	}
	case 10:
	{
		MessageDialog msg("请耐心等待驾照制作完成！", "预约失败");
		msg.ShowAsync(); return;
	}
	}
	String^ path = IDBlock->Text + ".exm";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file) {
		long exam = wcstol(ExamBlock->Text->Data(), NULL, 10);
		long progress = wcstol(ProgressNumberBlock->Text->Data(), NULL, 10);
		String^ newExam = ref new String(std::to_wstring(++exam).c_str());
		String^ newState = ref new String(std::to_wstring(++progress).c_str());
		FileIO::WriteTextAsync(file, newExam);
		FileWR::FileWrite(newExam + ".exm");
		FileWR::FileWrite(IDBlock->Text + ".sta", newState);
		MessageDialog msg("预约成功!考试编号为" + newExam, "预约成功");
		msg.ShowAsync();
		ConfirmBtn->IsEnabled = false;
	});
}



void DrivingSchool::ReserveExam::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}
