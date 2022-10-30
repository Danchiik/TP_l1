#define _CRT_SECURE_NO_WARNINGS
#include "Keeper.h"
#include "Mebel.h"
#include "Car.h"
#include "Worker.h"


Keeper::Keeper()
{
	printf("Keeper() constructor called\n");
	size = 0;
	list = nullptr;
	setFileName((char*)"preset_file.txt");
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
}


void Keeper::setFileName(char* fn)
{
	fileName = new char[strlen(fn) + 1];
	strcpy(fileName, fn);
}

char* Keeper::getFileName()
{
	return fileName;
}

void Keeper::saveSettings()
{
	int c = 0;
	printf("\n\tsettings menu\n-1 back\n1 see current file name\n2 edit file name\n");
	while (1)
	{
		takeInt(&c);
		switch (c)
		{
		case -1:
			return;

		case 1:
			printf("file name: %s\n", getFileName());
			break;

		case 2:
		{
			printf("enter new file name value\n");
			char* s = takeS();
			setFileName(s);
			printf("new value set\n");
		}
		break;

		default:
			printf("invalid input\n");
		}
	}

}

void Keeper::save()
{
	FILE* fpout = fopen(getFileName(), "w");
	if (fpout == NULL)
	{
		printf("couldn't open file for writing\n");
		return;
	}

	fprintf(fpout, "%d\n", size);

	for (int i = 0; i < size; i++)
	{
		list[i]->fileSave(fpout, i);
	}


	fclose(fpout);
}


void Keeper::load()
{
	FILE* fpin = fopen(getFileName(), "r");
	if (fpin == NULL)
	{
		printf("couldn't open file for writing\n");
		return;
	}
	int n = 0;
	if (fscanf(fpin, "%d\n", &n) != 1)
		throw (char*)"data corrupted\n";

	if (n <= 0)
		throw (char*)"data corrupted\n";
	int id;
	char c;
	for (int i = 0; i < n; i++)
	{
		if(fscanf(fpin, "%d%c\n", &id, &c)!= 2)
			throw (char*)"data corrupted\n";

		if (id != i)
		{
			fclose(fpin);
			throw (char*)"data corrupted\n";
		}
		switch (c)
		{
		case 'm':
			if (addMebel(fpin) == -1)
			{
				fclose(fpin);
				throw (char*)"data corrupted\n";
			}
			break;

			case 'w':if (addWorker(fpin) == -1)
			{
				fclose(fpin);
				throw (char*)"data corrupted\n";
			}
				break;

			case 'c':if (addCar(fpin) == -1)
			{
				fclose(fpin);
				throw (char*)"data corrupted\n";
			}
				break;

			default:
			{
				fclose(fpin);
				throw (char*)"data corrupted\n";
			}
		}

	}

	fclose(fpin);
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

int Keeper::addMebel(FILE* f)
{
	char* t, *c, *m; int h, w, d, p;
	int len = 0;
	if (fscanf(f, "%d ", &len) != 1) return -1; t = new char[len + 1]; fgets(t, len + 1, f);
	if (fscanf(f, "%d ", &len) != 1) return -1;  c = new char[len + 1]; fgets(c, len+1, f);
	if (fscanf(f, "%d ", &len) != 1) return -1; m = new char[len + 1]; fgets(m, len+1, f);
	if (fscanf(f, "%dx%dx%d\n", &h, &w, &d) != 3)
		return -1;
	if (fscanf(f, "%d\n", &p) != 1)
		return -1;

	Factory* mebel = new Mebel(t, h, w, d, c, m, p);
	*this + mebel;

	return 0;
}

int Keeper::addCar(FILE* f)
{
	char* br,* m,* n; 
	int len = 0;
	if (fscanf(f, "%d ", &len) != 1) return -1; br = new char[len + 1]; fgets(br, len + 1, f);
	if (fscanf(f, "%d ", &len) != 1) return -1;  m = new char[len + 1]; fgets(m, len + 1, f);
	if (fscanf(f, "%d ", &len) != 1) return -1; n = new char[len + 1]; fgets(n, len + 1, f);

	Factory* car = new Car(br, m, n);
	*this + car;

	return 0;
}

int Keeper::addWorker(FILE* f)
{

	char *fio, *t, *adr, *ph; int  p;
	int len = 0;
	if (fscanf(f, "%d ", &len) != 1) return -1; fio = new char[len + 1]; fgets(fio, len + 1, f);
	if (fscanf(f, "%d ", &len) != 1) return -1;  t = new char[len + 1]; fgets(t, len + 1, f);
	if (fscanf(f, "%d ", &len) != 1) return -1; adr = new char[len + 1]; fgets(adr, len + 1, f);
	if (fscanf(f, "%d ", &len) != 1) return -1; ph = new char[len + 1]; fgets(ph, len + 1, f);

	if (fscanf(f, "%d\n", &p) != 1)
		return -1;

	Factory* worker = new Worker(fio, t, adr, ph, p);
	*this + worker;

	return 0;
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
	while (1)
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

