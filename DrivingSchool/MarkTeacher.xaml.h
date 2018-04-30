//
// MarkTeacher.xaml.h
// MarkTeacher 类的声明
//

#pragma once

#include "MarkTeacher.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class MarkTeacher sealed
	{
	public:
		MarkTeacher();
	private:
		void GetTeacher();
		void ResetBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void SearchBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void GetScore();
		void GetHistory();
		void GetProgress();
	};
}
