//
// AddTeacherThree.xaml.cpp
// AddTeacherThree 类的实现
//

#include "pch.h"
#include "AddTeacherThree.xaml.h"

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

AddTeacherThree::AddTeacherThree()
{
	InitializeComponent();
	// 设定页面ID
	// 如第一次使用，则初始化
	// 异步任务链：判断文件存在->（写入文件->读入文件）
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->TryGetItemAsync("TeachersThree.num")
	).then([&](IStorageItem^ item)
	{
		isExistBlock->Text = "0";
		if (item == nullptr)
		{
			WriteFile();
		}
		else
		{
			GetId();
		}
	});
}

// 写入一个名单文件并重新读入
void DrivingSchool::AddTeacherThree::WriteFile()
{
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->CreateFileAsync("TeachersThree.num", CreationCollisionOption::ReplaceExisting)).then([&](StorageFile^ File)
	{
		return FileIO::WriteTextAsync(File, "300001");
	}).then([&]() {
		GetId();
	});
}

// 读入名单文件
void DrivingSchool::AddTeacherThree::GetId()
{
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync("TeachersThree.num"))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		IDBlock->Text = previousOperation.get();
	});
}




// 重置文本
void DrivingSchool::AddTeacherThree::ResetButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	NameBox->Text = "";
	PasswordBox->Password = "";
	ConfirmPasswordBox->Password = "";
}

// 确认注册
void DrivingSchool::AddTeacherThree::ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// 判断两次密码一致
	wstring wpassword = PasswordBox->Password->Data();
	wstring wconfirmPassword = ConfirmPasswordBox->Password->Data();
	if (wpassword != wconfirmPassword)
	{
		MessageDialog msg("注册失败，两次密码不一致", "注册失败");
		msg.ShowAsync();
		PasswordBox->Password = "";
		ConfirmPasswordBox->Password = "";
		return;
	}

	// 实例化一个 Teacher 对象
	wstring wname = NameBox->Text->Data();
	wstring wID = IDBlock->Text->Data();
	Teacher tch(wID, wname, wpassword, 0);


	// 注册
	tch.TeacherRegister();

	// 修改下一个人的编号
	long ID = wcstol(IDBlock->Text->Data(), NULL, 10);
	FileWR::FileWrite("TeachersThree.num", ref new String(std::to_wstring(++ID).c_str()));
	MessageDialog msg("注册成功，ID为" + IDBlock->Text, "注册成功");
	msg.ShowAsync();
	Frame->GoBack();
}

// 返回登陆页面
void DrivingSchool::AddTeacherThree::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}
