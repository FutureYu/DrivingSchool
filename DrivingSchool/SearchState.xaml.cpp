//
// SearchState.xaml.cpp
// SearchState 类的实现
//

#include "pch.h"
#include "SearchState.xaml.h"

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

SearchState::SearchState()
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


// 获取学习进度 
void DrivingSchool::SearchState::GetProgress()
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
		case 0:
			ProgressBlock->Text = "您当前正在学习科目一，请及时预约科目一考试"; break;
		case 1:
			ProgressBlock->Text = "您已预约科目一考试，请积极准备考试"; break;
		case 2:
			ProgressBlock->Text = "您已通过科目一考试，请及时预约科目二教练"; break;
		case 3:
			ProgressBlock->Text = "您当前正在学习科目二，请及时预约科目二考试"; break;
		case 4:
			ProgressBlock->Text = "您已预约科目二考试，请积极准备考试"; break;
		case 5:
			ProgressBlock->Text = "您已通过科目二考试，请及时预约科目三教练"; break;
		case 6:
			ProgressBlock->Text = "您当前正在学习科目三，请及时预约科目三考试"; break;
		case 7:
			ProgressBlock->Text = "您已预约科目三考试，请积极准备考试"; break;
		case 8:
			ProgressBlock->Text = "您当前正在学习科目四，请及时预约科目四考试"; break;
		case 9:
			ProgressBlock->Text = "您已预约科目四考试，请积极准备考试"; break;
		case 10:
			ProgressBlock->Text = "恭喜您已通过考试！请耐心等待领取驾照"; break;
		}
	});
}



void DrivingSchool::SearchState::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}


