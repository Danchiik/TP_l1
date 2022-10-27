#include "Keeper.h"

//Keeper::

Keeper::Keeper()
{
	printf("Keeper() constructor called\n");
	size = 0;
	list = nullptr;
	strcpy(fileName, "preset_file.txt");
}

Keeper::Keeper(int s, Factory** l, char* fp)
{
	printf("Keeper(int s, Factory** l, char* fp) constructor called\n");
	size = s;
	list = l;
	strcpy(fileName, fp);
}

Keeper::~Keeper()
{
	printf("Keeper() destructor called\n");
	for (int i = 0; i < size; i++)
		delete []list;
	
	size = 0;
	strcpy(fileName, "preset_file.txt");
}


void Keeper::printAll()
{
	printf("All list items:\n");
	for (int i = 0; i < size; i++)
		list[i]->print();
	if (size == 0)
		printf("none found\n");
}






