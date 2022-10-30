#pragma once
#include "Factory.h"
#include "helper.h"

class Car : public Factory
{
	char* brand;
	char* model;
	char* number;

public:

	Car();
	Car(Car&);
	Car(char*, char*, char*);
	~Car();

	char* getModel();
	char* getBrand();
	char* getNumber();

	void setBrand(char*);
	void setModel(char*);
	void setNumber(char*);

	void edit() override;
	void print() override;
	void fileSave(FILE *, int) override;

};