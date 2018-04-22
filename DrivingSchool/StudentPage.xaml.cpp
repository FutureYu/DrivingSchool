//
// StudentPage.xaml.cpp
// StudentPage 类的实现
//

#include "pch.h"
#include "StudentPage.xaml.h"
#include "ChangePwd.xaml.h"
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
String ^ID;
void StudentPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	if (dynamic_cast<Platform::String^>(e->Parameter) != nullptr)
	{
		 ID = e->Parameter->ToString();
	}

	::Windows::UI::Xaml::Controls::Page::OnNavigatedTo(e);
}

StudentPage::StudentPage()
{
	InitializeComponent();
}



void DrivingSchool::StudentPage::PersonalInformation_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}

// 修改密码
void DrivingSchool::StudentPage::ChangePwd_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Object^ idNavi = ID;
	Frame->Navigate(ChangePwd::typeid,idNavi);
}

// 预约考试
void DrivingSchool::StudentPage::ReserveExam_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Object^ idNavi = ID;
	Frame->Navigate(ReserveExam::typeid,idNavi);
}
