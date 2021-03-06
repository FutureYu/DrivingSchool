﻿//
// AddTeacherThree.xaml.h
// AddTeacherThree 类的声明
//

#pragma once

#include "AddTeacherThree.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class AddTeacherThree sealed
	{
	public:
		AddTeacherThree();
		void WriteFile();
		void GetId();
	private:
		void BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ResetButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
