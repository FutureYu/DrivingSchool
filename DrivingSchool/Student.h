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
	wstring time;
	int status;
	
public:
	Student(wstring ID, wstring name, wstring password, wstring time, int status);
	
};


#endif // !STUDENT_H