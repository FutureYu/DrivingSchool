//
// CheckScore.xaml.cpp
// CheckScore 类的实现
//

#include "pch.h"
#include "CheckScore.xaml.h"

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

CheckScore::CheckScore()
{
	InitializeComponent();
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


void DrivingSchool::CheckScore::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}

// 查询考试编号
void DrivingSchool::CheckScore::CheckScoreBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ path = ExamBlock->Text + ".exm";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {

		try {
			// 读取成功
			if (previousOperation.get() == nullptr)
			{
				MessageDialog msg("您还未参加考试，或成绩尚未上传，请等待。考试编号为" + IDBlock->Text, "查询失败");
				msg.ShowAsync();
			}
			else
			{
				ScoreBlock->Text = previousOperation.get();
			}
		}
		catch (...) {
			// 读取失败
		}
	});
}

// 查询
void DrivingSchool::CheckScore::CheckExamBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	CheckExamBtn->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	CheckScoreBtn->Visibility = Windows::UI::Xaml::Visibility::Visible;
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	String^ path = IDBlock->Text + ".exm";
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {

		try {
			// 读取成功
			ExamBlock->Text = previousOperation.get();
		}
		catch (...) {
			// 读取失败
		}
	});
	
}
