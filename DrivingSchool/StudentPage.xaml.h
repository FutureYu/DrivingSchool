//
// StudentPage.xaml.h
// StudentPage 类的声明
//

#pragma once

#include "StudentPage.g.h"
#include "iostream"
using namespace std;

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class StudentPage sealed
	{
	public:
		StudentPage();
	private:
		void PersonalInformation_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ChangePwd_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ReserveExam_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CheckScore_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
