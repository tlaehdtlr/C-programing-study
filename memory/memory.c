#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
	char* str = NULL;
	printf("%s \n", str);
	str = (char*)malloc(20);
	printf("%s \n", str);
	strcpy_s(str, "æ»≥Á«œººø‰");
	printf("%s \n", str);
	free(str);
	printf("%s \n", str);	
	*/

	int* p = (int*)malloc(sizeof(int) * 3);


	p[0] = 1;

	p[1] = 2;

	p[2] = 3;
	printf("%d \n", p);
	printf("%d\t%d\t%d\n", p[0], p[1], p[2]);

	free(p);


	return 0;
}