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
	void StudentRegister();
};


#endif // !STUDENT_H