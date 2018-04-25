//
// Register.xaml.h
// Register 类的声明
//

#pragma once

#include "Register.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Register sealed
	{
	public:
		Register();
	private:
		void WriteFile();
		void GetId();
		void ReNavigate();
		void ResetButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
