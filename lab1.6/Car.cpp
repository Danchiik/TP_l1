#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"

Car::Car()
{
	printf("Car() constructor called\n");
	setBrand((char*)"");
	setModel((char*)"");
	setNumber((char*)"");
}

Car::Car(Car& obj)
{
	printf("Car(Car& obj) constructor called\n");

	setBrand(obj.getBrand());
	setModel(obj.getModel());
	setNumber(obj.getNumber());
}


Car::Car(char* br, char* mod, char* num) : brand(br), model(mod), number(num)
{
	printf("Car(char* br, char* mod, char* num) constructor called\n");
}

Car::~Car()
{
	printf("~Car() destructor called\n");
	delete brand;
	delete model;
	delete number;
}



char* Car::getModel()
{
	return model;
}

char* Car::getBrand()
{
	return brand;
}

char* Car::getNumber()
{
	return number;
}


void Car::setBrand(char* v)
{
	delete brand; brand = new char[strlen(v) + 1];
	strcpy(brand, v);
}

void Car::setModel(char* v)
{
	delete model; model = new char[strlen(v) + 1];
	strcpy(model, v);
}

void Car::setNumber(char* v)
{
	delete number; number = new char[strlen(v) + 1];
	strcpy(number, v);
}



void Car::print()
{
	printf("CAR \n");
	printf("brand - %s\n", brand);
	printf("model - %s\n", model);
	printf("number - %s\n", number);
}


void Car::edit()
{
	print();

	int c = 0;
	char* s; int v;
	while (1)
	{
		printf("\n\tedit car menu\n");
		printf("-1 back\n\tedit\n1 brand\n2 model\n3 number\n");
		takeInt(&c);
		switch (c)
		{
		case -1:
			return;

		case 1:
			printf("enter new brand value\n");
			s = takeS();
			setBrand(s);
			break;

		case 2:
			printf("enter new model value\n");
			s = takeS();
			setModel(s);
			break;

		case 3:
			printf("enter new number value\n");
			s = takeS();
			setNumber(s);
			break;

		default:
			printf("invalid input\n");

		}
	}
}