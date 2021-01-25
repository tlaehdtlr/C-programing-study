#include <stdio.h>

int main()
{	
	/*int N;
	scanf_s("%d", &N);
	for (int num = 1; num <= N; num++)
	{
		do
		{
			if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9)
			{
				printf("-");
			}
			else
			{
				printf("%d", num % 10);
			}
			num /= 10;
		} while (num);
		printf(" ");
	}		*/

	int a = 534;
	do
	{
		printf("%d \n", a%10);
		a /= 10;
	} while (a);

	return 0;
}