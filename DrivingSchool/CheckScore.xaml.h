//
// CheckScore.xaml.h
// CheckScore 类的声明
//

#pragma once

#include "CheckScore.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class CheckScore sealed
	{
	public:
		CheckScore();
	private:
		void BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CheckScoreBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CheckExamBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
