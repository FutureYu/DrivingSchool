
#pragma once

#ifndef PEOPLE_H
#define PEOPLE_H
#include <iostream>
using namespace std;

class People
{
protected:
	wstring ID;
	wstring name;
	wstring password;


public:
	People();
	People(wstring ID, wstring name, wstring password);
	
};


#endif // !PEOPLE_H