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

#include "UplodeScore.xaml.h"

void ::DrivingSchool::UplodeScore::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///UplodeScore.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::DrivingSchool::UplodeScore::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
    case 1:
        {
            this->BackButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->BackButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::UplodeScore::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&UplodeScore::BackButton_Click);
        }
        break;
    case 2:
        {
            this->IDBox = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
        }
        break;
    case 3:
        {
            this->ScoreBox = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
        }
        break;
    case 4:
        {
            this->ConfirmBtn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ConfirmBtn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::UplodeScore::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&UplodeScore::ConfirmBtn_Click);
        }
        break;
    case 5:
        {
            this->ResetBtn = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->ResetBtn))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::DrivingSchool::UplodeScore::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&UplodeScore::ResetBtn_Click);
        }
        break;
    case 6:
        {
            this->isExistBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    case 7:
        {
            this->ExamIDBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    case 8:
        {
            this->StateBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    case 9:
        {
            this->TeacherStateBlock = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    case 10:
        {
            this->TotalPath = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::DrivingSchool::UplodeScore::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}

#pragma warning(pop)


