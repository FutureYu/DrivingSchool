//
// SearchState.xaml.h
// SearchState 类的声明
//

#pragma once

#include "SearchState.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class SearchState sealed
	{
	public:
		SearchState();
	private:
		void GetProgress();
		void BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
