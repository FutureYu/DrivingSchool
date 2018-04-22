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

	// 读取ID
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync("ID.id"))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		try {
			// 读取成功
			IDBlock->Text = previousOperation.get();
		}
		catch (...) {
			// 读取失败
		}
	});


}



// 确认注册
void DrivingSchool::ReserveExam::ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ path = IDBlock->Text + ".exm";
	long exam = wcstol(ExamBlock->Text->Data(), NULL, 10);
	String^ newExam = ref new String(std::to_wstring(++exam).c_str());
	FileWR::FileWrite(path,newExam );
	FileWR::FileWrite(newExam + ".exm", "");
	MessageDialog msg("预约成功!考试编号为" + newExam, "预约成功");
	msg.ShowAsync();
}

// 查询学习进度
void DrivingSchool::ReserveExam::SearchBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ path = IDBlock->Text + ".sta";

	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		try {
			// 读取成功
			long progress = wcstol(previousOperation.get()->Data(), NULL, 10);
			ProgressBlock->Text = "您当前正在学习科目" + (progress + 1).ToString() + ",将为您预约科目" + (progress + 1).ToString();
		}
		catch (...) {
			// 读取失败
		}
	});
}

// 查询考试编号
void DrivingSchool::ReserveExam::SearchExam_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ path = IDBlock->Text + ".exm";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		try {
			// 读取成功
			long exam = wcstol(previousOperation.get()->Data(), NULL, 10);
			ExamBlock->Text = exam.ToString();

			ConfirmBtn->Visibility = Windows::UI::Xaml::Visibility::Visible;
			SearchExamBtn->Visibility = Windows::UI::Xaml::Visibility::Collapsed;

		}
		catch (...) {
			// 读取失败
		}
	});
}


void DrivingSchool::ReserveExam::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}
