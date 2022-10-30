#define _CRT_SECURE_NO_WARNINGS
#include "Keeper.h"
#include "Mebel.h"
#include "Car.h"
#include "Worker.h"

//Keeper::

Keeper::Keeper()
{
	printf("Keeper() constructor called\n");
	size = 0;
	list = nullptr;
	fileName = new char[strlen("preset_file.txt") + 1];
	strcpy(fileName, "preset_file.txt");
}

Keeper::Keeper(int s, Factory** l, char* fp): size(s), list(l), fileName(fp)
{
	printf("Keeper(int s, Factory** l, char* fp) constructor called\n");
}

Keeper::~Keeper()
{
	printf("Keeper() destructor called\n");
	for (int i = 0; i < size; i++)
		delete list[i];
	
	size = 0;
	strcpy(fileName, "preset_file.txt");
}



void Keeper::printAll()
{
	printf("All list items:\n");
	for (int i = 0; i < size; i++)
	{
		printf("\n\t%d\t", i+1);
		list[i]->print();
	}
	if (size == 0)
		printf("none found\n");
}


void Keeper::operator+(Factory* obj)
{
	size += 1;
	Factory** created = new Factory * [size];
	for (int i = 0; i < size - 1; i++)
	{
		created[i] = list[i];
	}

	created[size - 1] = obj;
	list = created;
	
}


void Keeper::addMebel()
{
	Factory* mebel = new Mebel;
	*this + mebel;
	printf("new mebel added\n");
}

void Keeper::addCar()
{
	Factory* car = new Car;
	*this + car;
	printf("new car added\n");
}
void Keeper::addWorker()
{
	Factory* worker = new Worker;
	*this + worker;
	printf("new worker added\n");
}


int Keeper::add()
{
	int typeToAdd = 0;
	printf("add menu\n-1 back\n1 mebel\n2 worker\n3 car\n");
	while (typeToAdd == 0)
	{
		takeInt(&typeToAdd);
		switch (typeToAdd)
		{
		case -1:
			return 0;
		case 1:
			addMebel();
			break;
		case 2:
			addWorker();
			break;
		case 3:
			addCar();
			break;
		default:
			printf("invalid input\n");
			typeToAdd = 0;
			
		}
	}

}


void Keeper::edit()
{
	if (size == 0)
	{	
		printf("list is empty\n");
		return;
	}

	int c = 0;
	
	while (1)
	{
		printf("edit keeper menu\n-1 back\n1 - %d edit\n", size);
		takeInt(&c);
		switch (c)
		{
		case -1:
			return;

		default:
			if (c < 1 || c > size)
				printf("invalid input\n");
			else
				list[c-1]->edit();

		}
	}
}

void Keeper::del(int id)
{
	delete list[id];
	for (int i = id; i < size - 1; i++)
	{
		list[i] = list[i + 1];
	}
	size--;
}

void Keeper::remove()
{
	if (size == 0)
	{
		printf("list is empty\n");
		return;
	}

	int c = 0;

	while (1)
	{
		printf("remove keeper menu\n-1 back\n1 - %d remove\n", size);
		takeInt(&c);
		switch (c)
		{
		case -1:
			return;

		default:
			if (c < 1 || c > size)
				printf("invalid input\n");
			else
			{
				del(c - 1);
				printf("removed\n");
				if (size == 0)
					return;
			}

		}
	}
}

