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

#include "Register.xaml.h"

void ::DrivingSchool::Register::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///Register.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::DrivingSchool::Register::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
    case 1:
        {
            this->BackButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->BackButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::Register::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&Register::BackButton_Click);
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
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ConfirmButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::Register::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&Register::ConfirmButton_Click);
        }
        break;
    case 6:
        {
            this->ResetButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ResetButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::Register::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&Register::ResetButton_Click);
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

::Windows::UI::Xaml::Markup::IComponentConnector^ ::DrivingSchool::Register::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}

#pragma warning(pop)


