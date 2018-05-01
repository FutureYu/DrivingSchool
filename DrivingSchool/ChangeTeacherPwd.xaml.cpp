//
// ChangeTeacherPwd.xaml.cpp
// ChangeTeacherPwd 类的实现
//

#include "pch.h"
#include "ChangeTeacherPwd.xaml.h"

using namespace DrivingSchool;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// https://go.microsoft.com/fwlink/?LinkId=234238 上介绍了“空白页”项模板

ChangeTeacherPwd::ChangeTeacherPwd()
{
	InitializeComponent();
}

// 确认
void DrivingSchool::ChangeTeacherPwd::ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	wstring wpassword = PwdBox->Password->Data();
	wstring wconfirmPassword = ConfirmPwdBox->Password->Data();
	if (wpassword != wconfirmPassword)
	{
		MessageDialog msg("注册失败，两次密码不一致", "注册失败");
		msg.ShowAsync();
		PwdBox->Password = "";
		ConfirmPwdBox->Password = "";
		return;
	}

	String ^pwdPath = IDBox->Text + L".pwd";
	FileWR::FileWrite(pwdPath, PwdBox->Password);
	MessageDialog msg("更改成功，请重新登录", "更改成功");
	IDBox->Text = "";
	PwdBox->Password = "";
	ConfirmPwdBox->Password = "";
	msg.ShowAsync();
}

// 后退
void DrivingSchool::ChangeTeacherPwd::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}

// 重置
void DrivingSchool::ChangeTeacherPwd::ResetBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	IDBox->Text = "";
	PwdBox->Password = "";
	ConfirmPwdBox->Password = "";
}
