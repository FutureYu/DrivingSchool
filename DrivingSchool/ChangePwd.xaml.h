//
// ChangePwd.xaml.h
// ChangePwd 类的声明
//

#pragma once

#include "ChangePwd.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ChangePwd sealed
	{
	public:
		ChangePwd();
	private:
		void ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ResetBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
