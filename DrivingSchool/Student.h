#pragma once
#include "People.h"
#include <iostream>
using namespace std;
#ifndef STUDENT_H
#define STUDENT_H

class Student :
	public People
{
private:
	int status;
	
public:
	Student(wstring ID, wstring name, wstring password, int status);
	static void StudentRegister(Student stu);
};


#endif // !STUDENT_H