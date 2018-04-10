#include "pch.h"
#include "Student.h"
#include <iostream>
#include "FileWR.h"

using namespace Windows::Storage;
using namespace concurrency;
using namespace std;
using namespace Platform;

Student::Student(wstring ID, wstring name, wstring password, int status):People(ID,name,password)
{
	this->status = status;
}

// 注册一个学生
void Student::StudentRegister(Student stu)
{
	// 先创建路径
	wstring wnamePath = stu.ID + L".nam";
	String ^namePath = ref new String(wnamePath.c_str());

	wstring wpwdPath = stu.ID + L".pwd";
	String ^pwdPath = ref new String(wpwdPath.c_str());

	wstring wexmPath = stu.ID + L".exm";
	String ^exmPath = ref new String(wexmPath.c_str());

	wstring wstaPath = stu.ID + L".sta";
	String ^staPath = ref new String(wstaPath.c_str());

	// 创建写入内容
	wstring wstaContent = L"0";
	String ^nameContent = ref new String(stu.name.c_str());
	String ^pwdContent = ref new String(stu.password.c_str());
	String ^exmContent = ref new String();
	String ^staContent = ref new String(wstaContent.c_str());

	// 将内容写入文件
	FileWR::FileWrite(namePath, nameContent);
	FileWR::FileWrite(pwdPath, pwdContent);
	FileWR::FileWrite(exmPath, exmContent);
	FileWR::FileWrite(staPath, staContent);
}


