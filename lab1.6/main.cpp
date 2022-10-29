#include "stdio.h"
#include "Factory.h"
#include "Mebel.h"
#include "Keeper.h"

void menuList()
{
	printf("main menu\n");
	printf("-1 exit\n");
	printf("1 print to screen\n");
	printf("2 add\n");


}

int menu()
{
	menuList();
	Keeper keep;


	int c = 0;
	while (1)
	{
		printf("main menu\n");
		takeInt(&c);
		switch (c)
		{
		case -1:
			return 0;
		case 1:
			keep.printAll();
			break;
		case 2:
			keep.add();
			break;

			default:
				printf("unknwon command inputed\n"); menuList();
		}
	}

	return -1;
}


int main()
{
	menu();
	return 0;
}