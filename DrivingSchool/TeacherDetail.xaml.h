//
// TeacherDetail.xaml.h
// TeacherDetail 类的声明
//

#pragma once

#include "TeacherDetail.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class TeacherDetail sealed
	{
	public:
		TeacherDetail();
	private:
		void GetName();
		void GetMark();
		void GetHistory();
		void GetProgress();
		void GetTeacherProgress();
		void GetID();
		void GetAvailable();
		void TimeOneBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void TimeTwoBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void TimeThreeBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void TimeFourBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void TimeFiveBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
