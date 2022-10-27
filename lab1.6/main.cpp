#include "stdio.h"
#include "Factory.h"
#include "Mebel.h"

void menuList()
{



}

int menu()
{
	Factory* meb = new Mebel((char*)"10",110,10,10, (char*)"10", (char*)"10",110);
	meb->print();
	return -1;
}


int main()
{
	menu();
	return 0;
}