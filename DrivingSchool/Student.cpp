#include "pch.h"
#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(wstring ID, wstring name, wstring password, wstring time ,int status)
{
	this->ID = ID;
	this->name = name;
	this->password = password;
	this->status = status;
	this->time = time;
}


