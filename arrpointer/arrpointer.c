#include <stdio.h>

int main()
{
	int a[2][3] = { {1,2,3},{6,5,4} };
	int (*b)[3] = a;
	a[1][1] = 1234;
	int i,j;
	for (i = 0; i < 2; i++)
	{		
		for (j = 0; j < 3; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	return 0;
}