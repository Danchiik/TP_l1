#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"


/*char* FIO;
	char* title;
	int payment;
	char* adress;
	char* phone;*/


Worker::Worker()
{
	printf("Worker() constructor called\n");
	FIO = new char[2];
	title = new char[2];
	adress = new char[2];
	phone = new char[2];

	strcpy(FIO, "");
	strcpy(title, "");
	strcpy(adress, "");
	strcpy(phone, "");
	payment = 0;
}

Worker::Worker(Worker& obj)
{
	printf("Worker(Worker& obj) constructor called\n");

	setFIO(obj.getFIO());
	setTitle(obj.getTitle());
	setAdress(obj.getAdress());
	setPhone(obj.getPhone());
	setPayment(obj.getPayment());
}


Worker::Worker(char* fio, char* t, char* adr, char* ph, int pay) : FIO(fio), title(t), adress(adr), phone(ph), payment(pay)
{
	printf("Worker(char* fio, char* t, char* adr, char* ph, int pay) constructor called\n");
}

Worker::~Worker()
{
	printf("~Worker() destructor called\n");
	delete FIO;
	delete title;
	delete adress;
	delete phone;
	payment = 0;
}


char* Worker::getFIO()
{
	return FIO;
}

char* Worker::getTitle()
{
	return title;
}


char* Worker::getAdress()
{
	return adress;
}

char* Worker::getPhone()
{
	return phone;
}

int Worker::getPayment()
{
	return payment;
}



void Worker::setFIO(char* v)
{
	delete FIO; FIO = new char[strlen(v) + 1];
	strcpy(FIO, v);
}

void Worker::setTitle(char* v)
{
	delete title; title = new char[strlen(v) + 1];
	strcpy(title, v);
}

void Worker::setAdress(char* v)
{
	delete adress; adress = new char[strlen(v) + 1];
	strcpy(adress, v);
}

void Worker::setPhone(char* v)
{
	delete phone; phone = new char[strlen(v) + 1];
	strcpy(phone, v);
}

void Worker::setPayment(int v)
{
	payment = v;
}


void Worker::print()
{
	printf("WORKER \n");
	printf("FIO - %s\n", FIO);
	printf("title - %s\n", title);
	printf("adress - %s\n", adress);
	printf("phone - %s\n", phone);
	printf("payment - %s\n", payment);
}