﻿//
// AdminPage.xaml.cpp
// AdminPage 类的实现
//

#include "pch.h"
#include "AdminPage.xaml.h"
#include "UplodeScore.xaml.h"
#include "AddTeacherTwo.xaml.h"
#include "AddTeacherThree.xaml.h"

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
