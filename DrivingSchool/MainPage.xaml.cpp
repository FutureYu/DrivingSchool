//
// MainPage.xaml.cpp
// MainPage 类的实现。
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "people.h"
#include "Register.xaml.h"
#include "Student.h"
#include "StudentPage.xaml.h"
#include "App.xaml.h"
#include "AdminPage.xaml.h"



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

MainPage::MainPage()
{
	InitializeComponent();
	FileWR::FileWrite("900001.pwd", "admin");
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
	wstring wID(IDBox->Text->Data());
	wstring wPassword(PasswordBox->Password->Data());
	wstring wpath = wID + L".pwd";
	String^ path = ref new String(wpath.c_str());
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;

	// 异步任务链：判断用户存在->（判断密码匹配->导航至下一页面）
	concurrency::create_task(storageFolder->TryGetItemAsync(path)
	).then([&](IStorageItem^ item)
	{
		if (item == nullptr)
		{
			MessageDialog msg("登录失败，用户不存在!", "登录失败");
			msg.ShowAsync();
			isExistBlock->Text = "0";
		}
		else
		{
			isExistBlock->Text = "1";
		}
	}).then([&]() {
		TryLogin();
	});
}

void DrivingSchool::MainPage::TryLogin()
{
	if (isExistBlock->Text == "1")
	{
		wstring wID(IDBox->Text->Data());
		wstring wPassword(PasswordBox->Password->Data());
		wstring wpath = wID + L".pwd";

		//读取密码
		String^ path = ref new String(wpath.c_str());
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;

		concurrency::create_task(storageFolder->GetFileAsync(path))
			.then([&](StorageFile^ file)
		{
			return FileIO::ReadTextAsync(file);
		}).then([&](concurrency::task<String^> previousOperation) {
			// 读取成功
			if (previousOperation.get() == PasswordBox->Password)
			{
				isPwdCorrectBlock->Text = "1";
				FileWR::FileWrite("ID.id", IDBox->Text);
			}
			else
			{
				isPwdCorrectBlock->Text = "0";
				MessageDialog msg("登录失败，请检查密码是否正确", "登录失败");
				msg.ShowAsync();
			}
		}).then([&]() {
			LoginNavigate();
		});
	}
	
}

void DrivingSchool::MainPage::LoginNavigate()
{
	if (isExistBlock->Text == "1" && isPwdCorrectBlock->Text == "1")
	{
		if (wcstol(IDBox->Text->Data(), NULL, 10)<200000)
		{
			// 学生登录
			Frame->Navigate(StudentPage::typeid);
		}
		else if (wcstol(IDBox->Text->Data(), NULL, 10) > 900000)
		{
			// 管理员登录
			Frame->Navigate(AdminPage::typeid);
		}
		
	}
}

// 导航至注册页面
void DrivingSchool::MainPage::RegisterButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(Register::typeid);
}



void DrivingSchool::MainPage::IDBox_KeyDown(Platform::Object^ sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs^ e)
{

}
