#pragma once
#include "helper.h"


class Factory
{
public:

	Factory() ;
	~Factory();
	virtual void print() {};
	virtual void fileSave(FILE*, int) {};
	virtual void edit() {};


};