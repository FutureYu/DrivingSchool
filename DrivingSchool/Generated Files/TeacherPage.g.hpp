﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#pragma warning(push)
#pragma warning(disable: 4100) // unreferenced formal parameter

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "TeacherPage.xaml.h"

void ::DrivingSchool::TeacherPage::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///TeacherPage.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::DrivingSchool::TeacherPage::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
    case 1:
        {
            this->BackButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
        }
        break;
    case 2:
        {
            this->PersonPic = safe_cast<::Windows::UI::Xaml::Controls::PersonPicture^>(__target);
        }
        break;
    case 3:
        {
            this->GreetingBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    case 4:
        {
            this->ViewStudentBtn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ViewStudentBtn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::TeacherPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&TeacherPage::ViewStudentBtn_Click);
        }
        break;
    case 5:
        {
            this->ViewMark = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ViewMark))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::TeacherPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&TeacherPage::ViewMark_Click);
        }
        break;
    case 6:
        {
            this->IDBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::DrivingSchool::TeacherPage::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}

#pragma warning(pop)


