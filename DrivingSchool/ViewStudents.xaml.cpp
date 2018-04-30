//
// ViewStudents.xaml.cpp
// ViewStudents 类的实现
//

#include "pch.h"
#include "ViewStudents.xaml.h"

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

ViewStudents::ViewStudents()
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
		GetName();
	});
}

void DrivingSchool::ViewStudents::GetName()
{
	for (long i = 1; i < 6; i++)
	{
		String^ path = IDBlock->Text + ref new String(std::to_wstring(i).c_str()) + ".stu";
		StorageFolder^ storageFolder = ApplicationData::Current->LocalFolder;
		concurrency::create_task(storageFolder->GetFileAsync(path))
			.then([&, i](StorageFile^ file)
		{
			return FileIO::ReadTextAsync(file);
		}).then([&, i](concurrency::task<String^> previousOperation) {
			if (previousOperation.get() != "")
			{
				StudentBlock->Text += previousOperation.get() + "\n";
			}
		});
	}
}