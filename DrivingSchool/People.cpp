#include "pch.h"
#include "People.h"
#include <iostream>

using namespace Platform;
using namespace std;
using namespace Windows::Storage;
using namespace concurrency;

People::People()
{

}

People::People(wstring ID, wstring name, wstring password)
{
	this->ID = ID;
	this->name = name;
	this->password = password;
}

// 自动判断人员类型并请求登陆
int People::UserLogin(wstring ID, wstring Password)
{
	

if (ID[0] == '9')
{
	// AdminLogin

}
else if (ID[0] == '8')
{
	// TeacherLogin

}
else if (ID[0] != '0')
{
	//StudentLogin

}
return 0;
}



