#pragma once
#include "helper.h"
#include "Factory.h"

class Keeper
{
	int size;
	Factory** list;

	char* fileName;

	int addMebel(FILE* f);
	int addWorker(FILE* f);
	int addCar(FILE* f);

	void addMebel();
	void addWorker();
	void addCar();

	void del(int);


public:

	Keeper();
	Keeper(int, Factory**, char*);
	~Keeper();

	int add();
	
	void operator+(Factory*);
	
	void edit();
	void remove();

	void printAll();

	void setFileName(char*);
	char* getFileName();

	void save();
	void load();

	void saveSettings();

};