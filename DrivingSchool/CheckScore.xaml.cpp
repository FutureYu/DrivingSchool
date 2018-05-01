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
		GetProgress();
	});
}

// 获取进度
void DrivingSchool::CheckScore::GetProgress()
{
	String^ path = IDBlock->Text + ".sta";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		long progress = wcstol(previousOperation.get()->Data(), NULL, 10);

		switch (progress)
		{
		case 2:
		case 5:
		case 8:
		case 10:
			GetExamId(); break;
		default:
			ScoreBlock->Text = "您还未参加考试，或成绩尚未上传，请等待！";
			return;
		}
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
	}).then([&]() {
		GetScore();
	});
}

// 查询考试成绩
void DrivingSchool::CheckScore::GetScore()
{
	String^ path = ExamBlock->Text + ".exm";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		ScoreBlock->Text += previousOperation.get();
	});
}

void DrivingSchool::CheckScore::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}