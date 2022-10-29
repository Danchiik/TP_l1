#pragma once
#include "helper.h"
#include "Factory.h"

class Keeper
{
	int size;
	Factory** list;

	char* fileName;
	void addMebel();
	void addWorker() {};
	void addCar() {};

public:

	Keeper();
	Keeper(int, Factory**, char*);
	~Keeper();

	int add();
	
	void operator+(Factory*);
	
	void edit();
	void remove();

	void printAll();

	void setfileName(char*);
	char* getfileName();

	void save();
	void load();

	void saveSettings();

};