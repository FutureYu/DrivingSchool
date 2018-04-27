//
// UplodeScore.xaml.cpp
// UplodeScore 类的实现
//

#include "pch.h"
#include "UplodeScore.xaml.h"

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

UplodeScore::UplodeScore()
{
	InitializeComponent();
}

void DrivingSchool::UplodeScore::ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	String^ path = IDBox->Text + ".exm";
	// 异步任务链：判断用户存在->找到考试编号->读状态
	concurrency::create_task(storageFolder->TryGetItemAsync(path)
	).then([&](IStorageItem^ item)
	{
		if (item == nullptr)
		{
			MessageDialog msg("上传失败，用户不存在!", "上传失败");
			msg.ShowAsync();
			isExistBlock->Text = "0";
			return;
		}
		else
		{
			isExistBlock->Text = "1";
		}
	}).then([&]() {
		if (isExistBlock->Text == "1")
		{
			StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
			String^ path = IDBox->Text + ".exm";
			concurrency::create_task(storageFolder->GetFileAsync(path))
				.then([&](StorageFile^ file)
			{
				return FileIO::ReadTextAsync(file);
			}).then([&](concurrency::task<String^> previousOperation) {
				ExamIDBlock->Text = previousOperation.get();
			});
		}
	}).then([&]() {
		if (isExistBlock->Text == "1")
		{
			StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
			String^ path = IDBox->Text + ".sta";
			concurrency::create_task(storageFolder->GetFileAsync(path))
				.then([&](StorageFile^ file)
			{
				return FileIO::ReadTextAsync(file);
			}).then([&](concurrency::task<String^> previousOperation) {
				StateBlock->Text = previousOperation.get();
			}).then([&]() {
				WriteScore();
			});
		}
	});
}

void DrivingSchool::UplodeScore::WriteScore()
{
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	// 写入成绩
	FileWR::FileWrite(ExamIDBlock->Text + ".exm", ScoreBox->Text);
	long score = wcstol(ScoreBox->Text->Data(), NULL, 10);
	long state = wcstol(StateBlock->Text->Data(), NULL, 10);
	if (state == 1)
	{
		if (score >= 90)
		{
			StateBlock->Text = "2";
		}
		else
		{
			StateBlock->Text = "0";
		}
	}
	else if (state == 4)
	{
		if (score >= 80)
		{
			StateBlock->Text = "5";
		}
		else
		{
			StateBlock->Text = "3";
		}
	}
	else if (state == 7)
	{
		if (score >= 90)
		{
			StateBlock->Text = "8";
		}
		else
		{
			StateBlock->Text = "6";
		}
	}
	else
	{
		if (score >= 90)
		{
			StateBlock->Text = "10";
		}
		else
		{
			StateBlock->Text = "9";
		}
	}

	// 写状态
	String^ path = IDBox->Text + ".sta";
	FileWR::FileWrite(path, StateBlock->Text);
	MessageDialog msg("上传成功!  考试编号为" + ExamIDBlock->Text + "  考试成绩是" + ScoreBox->Text , "上传成功");
	msg.ShowAsync();
}

void DrivingSchool::UplodeScore::ResetBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	IDBox->Text = "";
	ScoreBox->Text = "";
}


void DrivingSchool::UplodeScore::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}



