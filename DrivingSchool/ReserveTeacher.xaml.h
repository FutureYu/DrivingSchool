//
// ReserveTeacher.xaml.h
// ReserveTeacher 类的声明
//

#pragma once

#include "ReserveTeacher.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ReserveTeacher sealed
	{
	public:
		ReserveTeacher();
	private:
		void GetProgress();
		void GetTeachersTwo();
		void GetTeachersThree();
		void GetTeacher(long maxTeacher);
		void ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void UpdateTchid();
		void NavigateToTeacherDetail();
		void ResetBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
