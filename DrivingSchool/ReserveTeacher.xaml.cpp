//
// ReserveTeacher.xaml.cpp
// ReserveTeacher 类的实现
//

#include "pch.h"
#include "ReserveTeacher.xaml.h"
#include "TeacherDetail.xaml.h"

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

ReserveTeacher::ReserveTeacher()
{
	InitializeComponent();

	// 读取ID，考试编号，进度编号
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync("ID.id"))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		IDBlock->Text = previousOperation.get();
	}).then([&]()
	{
		GetProgress();
	});
}


// 获取学习进度 
void DrivingSchool::ReserveTeacher::GetProgress()
{
	String^ path = IDBlock->Text + ".sta";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		long progress = wcstol(previousOperation.get()->Data(), NULL, 10);

		if (progress == 2)
		{
			GetTeachersTwo();
		}
		else if (progress == 5)
		{
			GetTeachersThree();
		}
		else
		{
			MessageDialog msg("预约失败，您当前不能预约！" + IDBlock->Text, "预约失败");
			msg.ShowAsync();
			return;
		}
	});
}

// 获取二科教练总数
void DrivingSchool::ReserveTeacher::GetTeachersTwo()
{
	String^ path = "TeachersTwo.num";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		long maxTeacher = wcstol(previousOperation.get()->Data(), NULL, 10);
		GetTeacher(maxTeacher);
	});
}


// 获取三科教练总数
void DrivingSchool::ReserveTeacher::GetTeachersThree()
{
	String^ path = "TeachersThree.num";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		long maxTeacher = wcstol(previousOperation.get()->Data(), NULL, 10);
		GetTeacher(maxTeacher);
	});
}

void DrivingSchool::ReserveTeacher::GetTeacher(long maxTeacher)
{

	for (long i = 200001; i < maxTeacher; i++)
	{
		String^ path = ref new String(std::to_wstring(i).c_str()) + ".sta";
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		concurrency::create_task(storageFolder->GetFileAsync(path))
			.then([&,i](StorageFile^ file)
		{
			return FileIO::ReadTextAsync(file);
		}).then([&,i](concurrency::task<String^> previousOperation) {
			long stuNumber = wcstol(previousOperation.get()->Data(), NULL, 10);
			if (stuNumber < 5)
			{
				TeacherBlock->Text += (ref new String(std::to_wstring(i).c_str()) + "\n");
			}
		});
	}
}

void DrivingSchool::ReserveTeacher::ConfirmBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->CreateFileAsync("TchID.id", CreationCollisionOption::ReplaceExisting)).then([&](StorageFile^ File)
	{
		return FileIO::WriteTextAsync(File, TeacherIDBox->Text);
	}).then([&]()
	{
		NavigateToTeacherDetail();
	});
}

void DrivingSchool::ReserveTeacher::NavigateToTeacherDetail()
{
	Frame->Navigate(TeacherDetail::typeid);
}

void DrivingSchool::ReserveTeacher::ResetBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TeacherIDBox->Text = "";
}
