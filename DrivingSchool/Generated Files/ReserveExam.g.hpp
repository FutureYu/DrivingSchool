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

#include "ReserveExam.xaml.h"

void ::DrivingSchool::ReserveExam::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///ReserveExam.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::DrivingSchool::ReserveExam::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
        case 1:
            {
                this->IDBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 2:
            {
                this->ProgressBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 3:
            {
                this->SearchBtn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->SearchBtn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::ReserveExam::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&ReserveExam::SearchBtn_Click);
            }
            break;
        case 4:
            {
                this->ConfirmBtn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ConfirmBtn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::ReserveExam::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&ReserveExam::ConfirmBtn_Click);
            }
            break;
        case 5:
            {
                this->ExamBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 6:
            {
                this->ProgressNumberBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 7:
            {
                this->BackButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->BackButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::ReserveExam::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&ReserveExam::BackButton_Click);
            }
            break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::DrivingSchool::ReserveExam::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}

