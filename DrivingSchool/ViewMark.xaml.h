//
// ViewMark.xaml.h
// ViewMark 类的声明
//

#pragma once

#include "ViewMark.g.h"

namespace DrivingSchool
{
	/// <summary>
	/// 可用于自身或导航至 Frame 内部的空白页。
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ViewMark sealed
	{
	public:
		ViewMark();
	private:
		void GetName();
		void GetMark();
		void GetHistory();
	};
}
