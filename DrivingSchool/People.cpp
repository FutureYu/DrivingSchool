#include "pch.h"
#include "People.h"
#include <iostream>

using namespace Platform;
using namespace std;
using namespace Windows::Storage;
using namespace concurrency;



People::People(wstring ID, wstring name, wstring password)
{
	this->ID = ID;
	this->name = name;
	this->password = password;
}
