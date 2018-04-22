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

// ע��һ��ѧ��
void Student::StudentRegister(Student stu)
{
	// �ȴ���·��
	wstring wnamePath = stu.ID + L".nam";
	String ^namePath = ref new String(wnamePath.c_str());

	wstring wpwdPath = stu.ID + L".pwd";
	String ^pwdPath = ref new String(wpwdPath.c_str());

	wstring wexmPath = stu.ID + L".exm";
	String ^exmPath = ref new String(wexmPath.c_str());

	wstring wstaPath = stu.ID + L".sta";
	String ^staPath = ref new String(wstaPath.c_str());

	wstring wtchPath = stu.ID + L".tch";
	String ^tchPath = ref new String(wtchPath.c_str());

	// ����д������
	String ^nameContent = ref new String(stu.name.c_str());
	String ^pwdContent = ref new String(stu.password.c_str());
	String ^exmContent = ref new String((stu.ID + L"1000").c_str());


	// ������д���ļ�
	FileWR::FileWrite(namePath, nameContent);
	FileWR::FileWrite(pwdPath, pwdContent);
	FileWR::FileWrite(exmPath, exmContent);
	FileWR::FileWrite(staPath, "0");
	FileWR::FileWrite(tchPath, "0");
	FileWR::FileWrite(exmContent + ".exm", "");
}


