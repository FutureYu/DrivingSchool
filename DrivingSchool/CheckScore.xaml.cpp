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
	});
}

// 获取考试编号
void DrivingSchool::CheckScore::GetExamId()
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
		if (previousOperation.get() == nullptr)
		{
			MessageDialog msg("您还未参加考试，或成绩尚未上传，请等待。考试编号为" + IDBlock->Text, "查询失败");
			msg.ShowAsync();
		}
		else
		{
			ScoreBlock->Text = previousOperation.get();
		}
	});
}
