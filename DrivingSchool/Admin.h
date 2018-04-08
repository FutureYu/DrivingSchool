#pragma once
#include "People.h"

#ifndef ADMIN_H
#define ADMIN_H

class Admin :
	public People
{
public:
	Admin::Admin(wstring ID, wstring name, wstring password);
};


#endif // !ADMIN_H