//
// ViewMark.xaml.cpp
// ViewMark 类的实现
//

#include "pch.h"
#include "ViewMark.xaml.h"

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

ViewMark::ViewMark()
{
	InitializeComponent();
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync("ID.id"))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		IDBlock->Text = previousOperation.get();
	}).then([&]()
	{
		GetMark();
	}).then([&]()
	{
		GetHistory();
	});
}

// 获取分数
void DrivingSchool::ViewMark::GetMark()
{
	String^ path = IDBlock->Text + ".sco";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		MarkBar->Value = wcstol(previousOperation.get()->Data(), NULL, 10);
	});
}

// 获取评分人数
void DrivingSchool::ViewMark::GetHistory()
{
	String^ path = IDBlock->Text + ".his";
	StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
	concurrency::create_task(storageFolder->GetFileAsync(path))
		.then([&](StorageFile^ file)
	{
		return FileIO::ReadTextAsync(file);
	}).then([&](concurrency::task<String^> previousOperation) {
		HistoryBlock->Text = "已有" + previousOperation.get() + "做出评价";
	});
}
