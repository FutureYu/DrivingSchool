//
// AdminPage.xaml.cpp
// AdminPage 类的实现
//

#include "pch.h"
#include "AdminPage.xaml.h"
#include "UplodeScore.xaml.h"
#include "AddTeacherTwo.xaml.h"
#include "AddTeacherThree.xaml.h"
#include "ChangeTeacherPwd.xaml.h"

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

AdminPage::AdminPage()
{
	InitializeComponent();
	SYSTEMTIME time;
	GetLocalTime(&time);
	String^ greeting;
	if (time.wHour >= 5 && time.wHour < 9)
	{
		greeting = "早上好，管理员！\n我能为你做什么？";
	}
	else if (time.wHour >= 9 && time.wHour < 12)
	{
		greeting = "上午好，管理员！\n我能为你做什么？";
	}
	else if (time.wHour >= 12 && time.wHour < 14)
	{
		greeting = "中午好，管理员！\n我能为你做什么？";
	}
	else if (time.wHour >= 14 && time.wHour < 18)
	{
		greeting = "下午好，管理员！\n我能为你做什么？";
	}
	else
	{
		greeting = "晚上好，管理员！\n我能为你做什么？";
	}
	GreetingBlock->Text = greeting;
}


void DrivingSchool::AdminPage::UplodeScore_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(UplodeScore::typeid);
}


void DrivingSchool::AdminPage::AddTeacherTwo_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(AddTeacherTwo::typeid);
}


void DrivingSchool::AdminPage::AddTeacherThree_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(AddTeacherThree::typeid);
}


void DrivingSchool::AdminPage::EditTeacher_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(ChangeTeacherPwd::typeid);
}
