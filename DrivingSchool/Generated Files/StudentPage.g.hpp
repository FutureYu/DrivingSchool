﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "StudentPage.xaml.h"

void ::DrivingSchool::StudentPage::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///StudentPage.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::DrivingSchool::StudentPage::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
        case 1:
            {
                this->ChangePersonalInformation = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ChangePersonalInformation))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::StudentPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&StudentPage::ChangePersonalInformation_Click);
            }
            break;
        case 2:
            {
                this->ChangePwd = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ChangePwd))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::StudentPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&StudentPage::ChangePwd_Click);
            }
            break;
        case 3:
            {
                this->ReserveExam = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ReserveExam))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::StudentPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&StudentPage::ReserveExam_Click);
            }
            break;
        case 4:
            {
                this->CheckScore = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->CheckScore))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::StudentPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&StudentPage::CheckScore_Click);
            }
            break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::DrivingSchool::StudentPage::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}


