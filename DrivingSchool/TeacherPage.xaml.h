//
// TeacherPage.xaml.h
// TeacherPage 类的声明
//

#pragma once

#include "TeacherPage.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class TeacherPage sealed
	{
	public:
		TeacherPage();
	private:
		void GetName();
		void ViewStudentBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ViewMark_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
