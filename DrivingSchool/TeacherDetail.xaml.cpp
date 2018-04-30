//
// TeacherDetail.xaml.cpp
// TeacherDetail 类的实现
//

#include "pch.h"
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

TeacherDetail::TeacherDetail()
{
	InitializeComponent();

	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync("TchID.id"))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		TchIDBlock->Text = previousOperation.get();
	}).then([&]()
	{
		GetName();
	}).then([&]()
	{
		GetID();
	}).then([&]()
	{
		GetMark();
	}).then([&]()
	{
		GetHistory();
	}).then([&]()
	{
		GetAvailable();
	}).then([&]()
	{
		GetProgress(); 
	});
}


// 获取名字
void DrivingSchool::TeacherDetail::GetName()
{
	String^ path = TchIDBlock->Text + ".nam";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		NameBlock->Text = previousOperation.get();
		PersonPic->DisplayName = previousOperation.get();
	});
}

// 获取分数
void DrivingSchool::TeacherDetail::GetMark()
{
	String^ path = TchIDBlock->Text + ".sco";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		RatingCtrl->Value = (wcstol(previousOperation.get()->Data(), NULL, 10)/10);
	});
}

// 获取评分人数
void DrivingSchool::TeacherDetail::GetHistory()
{
	String^ path = TchIDBlock->Text + ".his";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		HistoryBlock->Text = "已有" + previousOperation.get() + "人做出评价";
	});
}

// 获取进度
void DrivingSchool::TeacherDetail::GetProgress()
{
	String^ path = IDBlock->Text + ".sta";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		ProgressBlock->Text = previousOperation.get();
	});
}


// 获取教练人数
void DrivingSchool::TeacherDetail::GetTeacherProgress()
{
	String^ path = TchIDBlock->Text + ".sta";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		TchProgressBlock->Text = previousOperation.get();
	});
}

// 获取ID
void DrivingSchool::TeacherDetail::GetID()
{
	String^ path = "ID.id";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		IDBlock->Text = previousOperation.get();
	});
}

// 获取空余时段
void DrivingSchool::TeacherDetail::GetAvailable()
{
	for (long i = 1; i < 6; i++)
	{
		String^ path = TchIDBlock->Text + ref new String(std::to_wstring(i).c_str()) + ".stu";
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		concurrency::create_task(storageFolder->GetFileAsync(path))
			.then([&, i](StorageFile^ file)
		{
			return FileIO::ReadTextAsync(file);
		}).then([&, i](concurrency::task<String^> previousOperation) {
			if (previousOperation.get() != "")
			{
				switch (i)
				{
				case 1:TimeOneBtn->IsEnabled = false; break;
				case 2:TimeTwoBtn->IsEnabled = false; break;
				case 3:TimeThreeBtn->IsEnabled = false; break;
				case 4:TimeFourBtn->IsEnabled = false; break;
				case 5:TimeFiveBtn->IsEnabled = false; break;
				}
			}
		});
	}
}

void DrivingSchool::TeacherDetail::TimeOneBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	FileWR::FileWrite(IDBlock->Text + ".tch", TchIDBlock->Text);
	FileWR::FileWrite(IDBlock->Text + ".sta", ref new String(std::to_wstring((wcstol(ProgressBlock->Text->Data(), NULL, 10) + 1)).c_str()));
	FileWR::FileWrite(TchIDBlock->Text + "1.stu", IDBlock->Text);
	FileWR::FileWrite(TchIDBlock->Text + ".sta", ref new String(std::to_wstring((wcstol(TchProgressBlock->Text->Data(), NULL, 10) + 1)).c_str()));
	MessageDialog msg("预约成功，教练编号为" + TchIDBlock->Text, "预约成功");
	msg.ShowAsync();
	TimeOneBtn->IsEnabled = false;
	TimeTwoBtn->IsEnabled = false;
	TimeThreeBtn->IsEnabled = false;
	TimeFourBtn->IsEnabled = false;
	TimeFiveBtn->IsEnabled = false;
}


void DrivingSchool::TeacherDetail::TimeTwoBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	FileWR::FileWrite(IDBlock->Text + ".tch", TchIDBlock->Text);
	FileWR::FileWrite(IDBlock->Text + ".sta", ref new String(std::to_wstring((wcstol(ProgressBlock->Text->Data(), NULL, 10) + 1)).c_str()));
	FileWR::FileWrite(TchIDBlock->Text + "2.stu", IDBlock->Text);
	FileWR::FileWrite(TchIDBlock->Text + ".sta", ref new String(std::to_wstring((wcstol(TchProgressBlock->Text->Data(), NULL, 10) + 1)).c_str()));
	MessageDialog msg("预约成功，教练编号为" + TchIDBlock->Text, "预约成功");
	msg.ShowAsync();
	TimeOneBtn->IsEnabled = false;
	TimeTwoBtn->IsEnabled = false;
	TimeThreeBtn->IsEnabled = false;
	TimeFourBtn->IsEnabled = false;
	TimeFiveBtn->IsEnabled = false;
}


void DrivingSchool::TeacherDetail::TimeThreeBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	FileWR::FileWrite(IDBlock->Text + ".tch", TchIDBlock->Text);
	FileWR::FileWrite(IDBlock->Text + ".sta", ref new String(std::to_wstring((wcstol(ProgressBlock->Text->Data(), NULL, 10) + 1)).c_str()));
	FileWR::FileWrite(TchIDBlock->Text + "3.stu", IDBlock->Text);
	FileWR::FileWrite(TchIDBlock->Text + ".sta", ref new String(std::to_wstring((wcstol(TchProgressBlock->Text->Data(), NULL, 10) + 1)).c_str()));
	MessageDialog msg("预约成功，教练编号为" + TchIDBlock->Text, "预约成功");
	msg.ShowAsync();
	TimeOneBtn->IsEnabled = false;
	TimeTwoBtn->IsEnabled = false;
	TimeThreeBtn->IsEnabled = false;
	TimeFourBtn->IsEnabled = false;
	TimeFiveBtn->IsEnabled = false;
}


void DrivingSchool::TeacherDetail::TimeFourBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	FileWR::FileWrite(IDBlock->Text + ".tch", TchIDBlock->Text);
	FileWR::FileWrite(IDBlock->Text + ".sta", ref new String(std::to_wstring((wcstol(ProgressBlock->Text->Data(), NULL, 10) + 1)).c_str()));
	FileWR::FileWrite(TchIDBlock->Text + "4.stu", IDBlock->Text);
	FileWR::FileWrite(TchIDBlock->Text + ".sta", ref new String(std::to_wstring((wcstol(TchProgressBlock->Text->Data(), NULL, 10) + 1)).c_str()));
	MessageDialog msg("预约成功，教练编号为" + TchIDBlock->Text, "预约成功");
	msg.ShowAsync();
	TimeOneBtn->IsEnabled = false;
	TimeTwoBtn->IsEnabled = false;
	TimeThreeBtn->IsEnabled = false;
	TimeFourBtn->IsEnabled = false;
	TimeFiveBtn->IsEnabled = false;
}


void DrivingSchool::TeacherDetail::TimeFiveBtn_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	FileWR::FileWrite(IDBlock->Text + ".tch", TchIDBlock->Text);
	FileWR::FileWrite(IDBlock->Text + ".sta", ref new String(std::to_wstring((wcstol(ProgressBlock->Text->Data(), NULL, 10) + 1)).c_str()));
	FileWR::FileWrite(TchIDBlock->Text + "5.stu", IDBlock->Text);
	FileWR::FileWrite(TchIDBlock->Text + ".sta", ref new String(std::to_wstring((wcstol(TchProgressBlock->Text->Data(), NULL, 10) + 1)).c_str()));
	MessageDialog msg("预约成功，教练编号为" + TchIDBlock->Text, "预约成功");
	msg.ShowAsync();
	TimeOneBtn->IsEnabled = false;
	TimeTwoBtn->IsEnabled = false;
	TimeThreeBtn->IsEnabled = false;
	TimeFourBtn->IsEnabled = false;
	TimeFiveBtn->IsEnabled = false;
}


void DrivingSchool::TeacherDetail::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Frame->GoBack();
}
