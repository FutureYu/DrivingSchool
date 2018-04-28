#pragma once
#include "People.h"
class Teacher :
	public People
{
private:
	int score;
	
	

public:
	Teacher(wstring ID, wstring name, wstring password, int score);
	void TeacherRegister();
	
};

