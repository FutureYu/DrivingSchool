#include "pch.h"
#include "Student.h"
#include <iostream>
#include "FileWR.h"

using namespace Windows::Storage;
using namespace concurrency;
using namespace std;
using namespace Platform;

Student::Student(wstring ID, wstring name, wstring password, int status)
{
	this->ID = ID;
	this->name = name;
	this->password = password;
	this->status = status;
}

// 注册一个学生
void Student::StudentRegister(Student stu)
{
	// 先创建路径
	wstring wpath = stu.ID + L".csv";
	String ^path = ref new String(wpath.c_str());

	// 创建写入内容
	wstring wcontent = stu.ID + L"," + stu.name + L"," + stu.password + L"," + L"0" + L"," + L"\r\n";
	String ^content = ref new String(wcontent.c_str());

	// 将内容写入文件
	FileWR::FileAppend(path, content);
}


