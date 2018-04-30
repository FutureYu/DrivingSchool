//
// StudentPage.xaml.cpp
// StudentPage 类的实现
//

#include "pch.h"
#include "StudentPage.xaml.h"
#include "ChangePwd.xaml.h"
#include "CheckScore.xaml.h"
#include "ReserveExam.xaml.h"
#include "ReserveTeacher.xaml.h"
#include "MarkTeacher.xaml.h"
#include "SearchState.xaml.h"
#include <Windows.h>




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

StudentPage::StudentPage()
{
	InitializeComponent();
	SYSTEMTIME time;
	GetLocalTime(&time);
	String^ greeting;
	if (time.wHour >= 5 && time.wHour < 9)
	{
	greeting = "早上好！";
	}
	else if (time.wHour >= 9 && time.wHour < 12)
	{
	greeting = "上午好！";
	}
	else if (time.wHour >= 12 && time.wHour < 14)
	{
	greeting = "中午好！";
	}
	else if (time.wHour >= 14 && time.wHour < 18)
	{
	greeting = "下午好！";
	}
	else
	{
	greeting = "晚上好！";
	}
	GreetingBlock->Text = greeting;
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync("ID.id"))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		IDBlock->Text = previousOperation.get();
	}).then([&]()
	{
		GetName();
	});
	String^ content = GreetingBlock->Text;
}

void DrivingSchool::StudentPage::GetName()
{
	String^ path = IDBlock->Text + ".nam";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		GreetingBlock->Text += previousOperation.get() + "\n我能为你做什么？";
	});
}

void DrivingSchool::StudentPage::ChangePwd_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(ChangePwd::typeid);
}

void DrivingSchool::StudentPage::CheckScore_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(CheckScore::typeid);
}

void DrivingSchool::StudentPage::ReserveExam_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(ReserveExam::typeid);
}

void DrivingSchool::StudentPage::ReserveTeacher_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(ReserveTeacher::typeid);
}

void DrivingSchool::StudentPage::MarkTeacher_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(MarkTeacher::typeid);
}


void DrivingSchool::StudentPage::SearchBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(SearchState::typeid);
}
