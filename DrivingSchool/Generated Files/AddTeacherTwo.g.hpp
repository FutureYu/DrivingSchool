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

#include "AddTeacherTwo.xaml.h"

void ::DrivingSchool::AddTeacherTwo::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///AddTeacherTwo.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::DrivingSchool::AddTeacherTwo::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
    case 1:
        {
            this->BackButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->BackButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::AddTeacherTwo::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&AddTeacherTwo::BackButton_Click);
        }
        break;
    case 2:
        {
            this->NameBox = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
        }
        break;
    case 3:
        {
            this->PasswordBox = safe_cast<::Windows::UI::Xaml::Controls::PasswordBox^>(__target);
        }
        break;
    case 4:
        {
            this->ConfirmPasswordBox = safe_cast<::Windows::UI::Xaml::Controls::PasswordBox^>(__target);
        }
        break;
    case 5:
        {
            this->ConfirmButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ConfirmButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::AddTeacherTwo::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&AddTeacherTwo::ConfirmButton_Click);
        }
        break;
    case 6:
        {
            this->ResetButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ResetButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::AddTeacherTwo::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&AddTeacherTwo::ResetButton_Click);
        }
        break;
    case 7:
        {
            this->IDBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    case 8:
        {
            this->isExistBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::DrivingSchool::AddTeacherTwo::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}

#pragma warning(pop)


