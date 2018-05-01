//
// ChangeTeacherPwd.xaml.h
// ChangeTeacherPwd 类的声明
//

#pragma once

#include "ChangeTeacherPwd.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ChangeTeacherPwd sealed
	{
	public:
		ChangeTeacherPwd();
		void ConfirmBtn_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void BackButton_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
		void ResetBtn_Click(Platform::Object ^ sender, Windows::UI::Xaml::RoutedEventArgs ^ e);
	};
}
