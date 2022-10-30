#define _CRT_SECURE_NO_WARNINGS

#include "helper.h"

int takeInt(void* _x)
{
	while (1)
	{
		printf(":= ");
		if (scanf("%d", _x) != 1)
			printf("invalid input, try again\n");
		else
		{
			if (getchar());
			return 1;
		}
		if (getchar());
	}
}

char* takeS()
{
	char buf[1200];
	printf(":= ");
	gets_s(buf);
		
	return buf;
}