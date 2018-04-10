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
	wstring ID(IDBox->Text->Data());
	wstring Password(PasswordBox->Password->Data());
	String^ path(IDBox->Text + L".csv"); // ToDo: 修改
	wstring wcontent;
	// 读取文件 
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;

	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		
		try {
			// 读取成功
			previousOperation.get();
		}
		catch (...) {
			// 读取失败

		}
	});





	People::UserLogin(ID, Password);
}

// 导航至注册页面
void DrivingSchool::MainPage::RegisterButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(Register::typeid);
}
