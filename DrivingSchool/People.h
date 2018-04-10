
#pragma once

#ifndef PEOPLE_H
#define PEOPLE_H
#include <iostream>
using namespace Platform;
using namespace std;

class People
{
protected:
	wstring ID;
	wstring name;
	wstring password;


public:
	static String^ fileContent;
	People();
	People(wstring ID, wstring name, wstring password);
	static int UserLogin(wstring ID, wstring Password);
	
	
};


#endif // !PEOPLE_H