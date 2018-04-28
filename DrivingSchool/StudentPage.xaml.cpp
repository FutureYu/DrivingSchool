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
