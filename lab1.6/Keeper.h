#pragma once
#include "helper.h"
#include "Factory.h"

class Keeper
{
	int size;
	Factory** list;

	char fileName[250];

public:

	Keeper();
	Keeper(int, void*);
	Keeper(Keeper&);
	
	~Keeper();

	void add();
	void edit();
	void remove();

	void printAll();

	void setfileName(char*);
	char* getfileName();

};