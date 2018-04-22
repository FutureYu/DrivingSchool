//
// MainPage.xaml.cpp
// MainPage 类的实现。
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <iostream>
#include "people.h"
#include "Register.xaml.h"
#include "FileWR.h"
#include "Student.h"
#include "StudentPage.xaml.h"
#include "App.xaml.h"

using namespace std;
using namespace DrivingSchool;

using namespace Windows::Storage;
using namespace concurrency;
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
using namespace Windows::UI::Popups;

// https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x804 上介绍了“空白页”项模板
String^ People::fileContent = "";
MainPage::MainPage()
{
	InitializeComponent();
}

// 重置文本框内容
void DrivingSchool::MainPage::ResetButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	IDBox->Text = "";
	PasswordBox->Password = "";
}

// 登陆
void MainPage::LoginButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// 获取Id与密码，并创建对象
	wstring wID(IDBox->Text->Data());
	wstring wPassword(PasswordBox->Password->Data());
	wstring wpath = wID + L".pwd";

	//读取密码
	String^ path = ref new String(wpath.c_str());
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	if (fileContent->Text != "SuccessFully,click again to login")
	{
		concurrency::create_task(storageFolder->GetFileAsync(path))
			.then([&](StorageFile^ file)
		{
			return FileIO::ReadTextAsync(file);
		}).then([&](concurrency::task<String^> previousOperation) {
			try {
				// 读取成功
				if (previousOperation.get() == PasswordBox->Password)
				{
					fileContent->Text = "SuccessFully,click again to login";
					FileWR::FileWrite("ID.id", IDBox->Text);
					MessageDialog msg("登录成功，再次点击登录键以确认", "登录成功");
					msg.ShowAsync();
				}
				else
				{
					MessageDialog msg("登录失败，请检查密码是否正确", "登录失败");
					msg.ShowAsync();
				}
			}
			catch (...) {
				// 读取失败
			}
		});
	}
	
	if (fileContent->Text == "SuccessFully,click again to login")
	{
		Object^ ID = ref new String(wID.c_str());
		Frame->Navigate(StudentPage::typeid,ID);
	}
	
	
}

// 导航至注册页面
void DrivingSchool::MainPage::RegisterButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(Register::typeid);
}
