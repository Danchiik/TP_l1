#include "stdio.h"
#include "Factory.h"
#include "Mebel.h"
#include "Keeper.h"

void menuList()
{
	printf("main menu\n");
	printf("-1 exit\n");
	printf("0 see menu\n");
	printf("1 print to screen\n");
	printf("2 add\n");
	printf("3 edit\n");
	printf("4 remove\n");


}

int menu()
{
	menuList();
	Keeper keep;


	int c = 0;
	while (1)
	{
		printf("\n\tmain menu\n");
		takeInt(&c);
		switch (c)
		{
		case -1:
			return 0;
		case 0:
			menuList();
			break;
		case 1:
			keep.printAll();
			break;
		case 2:
			keep.add();
			break;
		case 3:
			keep.edit();
			break;
		case 4:
			keep.remove();
			break;

		default:
			printf("unknwon command inputed\nenter 0 to see menu\n");
		}
	}

	return -1;
}


int main()
{
	menu();
	return 0;
}