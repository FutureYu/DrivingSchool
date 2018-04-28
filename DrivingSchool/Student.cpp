#include "pch.h"
#include "Student.h"

using namespace Windows::Storage;
using namespace concurrency;
using namespace std;
using namespace Platform;

Student::Student(wstring ID, wstring name, wstring password, int status):People(ID,name,password)
{
	this->status = status;
}

void Student::StudentRegister()
{
	// 先创建路径
	wstring wnamePath = this->ID + L".nam";
	String ^namePath = ref new String(wnamePath.c_str());

	wstring wpwdPath = this->ID + L".pwd";
	String ^pwdPath = ref new String(wpwdPath.c_str());

	wstring wexmPath = this->ID + L".exm";
	String ^exmPath = ref new String(wexmPath.c_str());

	wstring wstaPath = this->ID + L".sta";
	String ^staPath = ref new String(wstaPath.c_str());

	wstring wtchPath = this->ID + L".tch";
	String ^tchPath = ref new String(wtchPath.c_str());

	// 创建写入内容
	String ^nameContent = ref new String(this->name.c_str());
	String ^pwdContent = ref new String(this->password.c_str());
	String ^exmContent = ref new String((this->ID + L"1000").c_str());


	// 将内容写入文件
	FileWR::FileWrite(namePath, nameContent);
	FileWR::FileWrite(pwdPath, pwdContent);
	FileWR::FileWrite(exmPath, exmContent);
	FileWR::FileWrite(staPath, "0");
	FileWR::FileWrite(tchPath, "0");
}


