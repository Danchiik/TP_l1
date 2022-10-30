#pragma once
#include "Factory.h"
#include "helper.h"

class Worker : public Factory
{
	char* type;

	char* color;
	char* material;
	int price;


	char* FIO;
	char* title;
	int payment;
	char* adress;
	char* phone;

public:

	Worker();
	Worker(Worker&);
	Worker(char*, char*, char*, char*, int);
	~Worker();

	char* getFIO();
	char* getTitle();
	char* getAdress();
	char* getPhone();
	int getPayment();

	void setFIO(char*);
	void setTitle(char*);
	void setAdress(char*);
	void setPhone(char*);
	void setPayment(int);


	void edit() override;
	void print() override;

};