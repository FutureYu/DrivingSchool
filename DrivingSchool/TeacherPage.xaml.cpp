//
// TeacherPage.xaml.cpp
// TeacherPage 类的实现
//

#include "pch.h"
#include "TeacherPage.xaml.h"
#include "ViewMark.xaml.h"
#include "ViewStudents.xaml.h"

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

TeacherPage::TeacherPage()
{
	InitializeComponent();
}


void DrivingSchool::TeacherPage::ViewStudentBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(ViewStudents::typeid);
}


void DrivingSchool::TeacherPage::ViewMark_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(ViewMark::typeid);

}
