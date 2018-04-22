//
// Register.xaml.cpp
// Register 类的实现
//

#include "pch.h"
#include "Register.xaml.h"
#include "Mainpage.xaml.h"

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

Register::Register()
{
	InitializeComponent();
	// 设定页面ID
	// 如第一次使用，则初始化
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;

	
	concurrency::create_task(storageFolder->TryGetItemAsync("Students.num")
	).then([&](IStorageItem^ item)
	{
		if (item == nullptr)
		{
			FileWR::FileWrite("Students.num", "100001");
			MessageDialog msg( "初始化成功，请手动点击返回键后重新注册","初始化成功！");
			msg.ShowAsync();
		}
		
	});

	concurrency::create_task( storageFolder->GetFileAsync("Students.num") )
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {

		try {
			// 读取成功
			IDBlock->Text = previousOperation.get();
		}
		catch (...) {
			// 读取失败
		}
	});
	
	
	

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
	FileWR::FileWrite("Students.num", ref new String(std::to_wstring(++ID).c_str()));
	MessageDialog msg("注册成功，ID为" + IDBlock->Text, "注册成功！");
	msg.ShowAsync();

}

// 返回登陆页面
void DrivingSchool::Register::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}




