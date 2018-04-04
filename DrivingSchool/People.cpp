#include "pch.h"
#include "People.h"
#include <iostream>
using namespace std;

People::People()
{

}

People::People(wstring ID, wstring name, wstring password)
{
	this->ID = ID;
	this->name = name;
	this->password = password;
}



