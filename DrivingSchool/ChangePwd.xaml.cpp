//
// ChangePwd.xaml.cpp
// ChangePwd 类的实现
//

#include "pch.h"
#include "ChangePwd.xaml.h"
#include "FileWR.h"
#include "MainPage.xaml.h"

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
using namespace Windows::Storage;
using namespace concurrency;
using namespace Windows::UI::Popups;

// https://go.microsoft.com/fwlink/?LinkId=234238 上介绍了“空白页”项模板

ChangePwd::ChangePwd()
{
	InitializeComponent();

	// 读取当前用户ID
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync("ID.id"))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		IDBlock->Text += previousOperation.get();
	});

}

// 确认
void DrivingSchool::ChangePwd::ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
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

	String ^pwdPath = IDBlock->Text + L".pwd";
	FileWR::FileWrite(pwdPath, PwdBox->Password);
	MessageDialog msg("更改成功，请重新登录", "更改成功");
	msg.ShowAsync();
	Frame->Navigate(MainPage::typeid);
}

// 后退
void DrivingSchool::ChangePwd::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}

// 重置
void DrivingSchool::ChangePwd::ResetBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	PwdBox->Password = "";
	ConfirmPwdBox->Password = "";
}
