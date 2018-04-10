//
// Register.xaml.cpp
// Register 类的实现
//

#include "pch.h"
#include "Register.xaml.h"
#include "Mainpage.xaml.h"
#include <iostream>
#include "student.h"
#include "FileWR.h"
#include <string>

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

// https://go.microsoft.com/fwlink/?LinkId=234238 上介绍了“空白页”项模板
//String^ FileWR::content = "";
Register::Register()
{
	InitializeComponent();
	// 设定ID

	String^str;
	//str = FileWR::FileRead("Students.con");
	IDBlock->Text = FileWR::FileRead("Students.con");

	//	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	//	concurrency::create_task(storageFolder->GetFileAsync("Students.csv"))
	//		.then([&](StorageFile^ file)
	//	{
	//		return FileIO::ReadTextAsync(file);
	//	}).then([&](concurrency::task<String^> previousOperation) {
	//
	//		try {
	//			// 读取成功
	//			IDBlock->Text = previousOperation.get();
	//		}
	//		catch (...) {
	//			// 读取失败
	//		}
	//	});
	//	
}

// 重置文本
void DrivingSchool::Register::ResetButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	NameBox->Text = "";
	PasswordBox->Password = "";
}

// 确认注册
void DrivingSchool::Register::ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{	// 实例化一个 Student 对象
	wstring wname = NameBox->Text->Data();
	wstring wpassword = PasswordBox->Password->Data();
	wstring wID = IDBlock->Text->Data();
	Student stu(wID, wname, wpassword, 0);

	// 注册
	Student::StudentRegister(stu);

	// 修改下一个人的编号
	long ID = wcstol(IDBlock->Text->Data(), NULL, 10);
	String ^tmp = ref new String(std::to_wstring(++ID).c_str());
	FileWR::FileWrite("Students.csv", tmp);
	IDBlock->Text = "OK";

}

// 返回登陆页面
void DrivingSchool::Register::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->Navigate(MainPage::typeid);
}




