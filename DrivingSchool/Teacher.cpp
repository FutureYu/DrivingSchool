#include "pch.h"
#include "Teacher.h"


Teacher::Teacher(wstring ID, wstring name, wstring password, int score):People(ID,name,password)
{
	this->score = score;	
}

void Teacher::TeacherRegister()
{
	// 先创建路径
	wstring wnamePath = this->ID + L".nam";
	String ^namePath = ref new String(wnamePath.c_str());

	wstring wpwdPath = this->ID + L".pwd";
	String ^pwdPath = ref new String(wpwdPath.c_str());

	wstring wstaPath = this->ID + L".sta";
	String ^staPath = ref new String(wstaPath.c_str());

	wstring wscorePath = this->ID + L".sco";
	String ^scorePath = ref new String(wscorePath.c_str());

	wstring wstuOnePath = this->ID + L"1.stu";
	String ^stuOnePath = ref new String(wstuOnePath.c_str());

	wstring wstuTwoPath = this->ID + L"2.stu";
	String ^stuTwoPath = ref new String(wstuTwoPath.c_str());

	wstring wstuThreePath = this->ID + L"3.stu";
	String ^stuThreePath = ref new String(wstuThreePath.c_str());

	wstring wstuFourPath = this->ID + L"4.stu";
	String ^stuFourPath = ref new String(wstuFourPath.c_str());

	wstring wstuFivePath = this->ID + L"5.stu";
	String ^stuFivePath = ref new String(wstuFivePath.c_str());

	wstring whisPath = this->ID + L".his";
	String ^hisPath = ref new String(whisPath.c_str());

	// 创建写入内容
	String ^nameContent = ref new String(this->name.c_str());
	String ^pwdContent = ref new String(this->password.c_str());


	// 将内容写入文件
	FileWR::FileWrite(namePath, nameContent);
	FileWR::FileWrite(pwdPath, pwdContent);
	FileWR::FileWrite(staPath, "0");
	FileWR::FileWrite(scorePath, "0");
	FileWR::FileWrite(stuOnePath);
	FileWR::FileWrite(stuTwoPath);
	FileWR::FileWrite(stuThreePath);
	FileWR::FileWrite(stuFourPath);
	FileWR::FileWrite(stuFivePath);
	FileWR::FileWrite(hisPath, "0");

}

