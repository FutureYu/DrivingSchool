#include "pch.h"
#include "Teacher.h"


Teacher::Teacher(wstring ID, wstring name, wstring password, int score, wstring currentStudent[8])
{
	this->ID = ID;
	this->name = name;
	this->password = password;
	this->score = score;
	for (size_t i = 0; i < 8; i++)
	{
		this->currentStudent[i] = currentStudent[i];
	}
	
}


