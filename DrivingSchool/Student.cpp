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

// ע��һ��ѧ��
void Student::StudentRegister(Student stu)
{
	// �ȴ���·��
	wstring wpath = stu.ID + L".csv";
	String ^path = ref new String(wpath.c_str());

	// ����д������
	wstring wcontent = stu.ID + L"," + stu.name + L"," + stu.password + L"," + L"0" + L"," + L"\r\n";
	String ^content = ref new String(wcontent.c_str());

	// ������д���ļ�
	FileWR::FileAppend(path, content);
}


