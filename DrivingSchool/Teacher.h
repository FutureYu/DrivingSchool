#pragma once
#include "People.h"
class Teacher :
	public People
{
private:
	int score;
	wstring currentStudent[8];
	

public:
	Teacher(wstring ID, wstring name, wstring password, int score, wstring currentStudent[8]);
	
};

