#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int nums[101] = { 0 };
void init();

int main()
{
	int T, tcase=0;
	scanf("%d", &T);

	for (int tc = 0; tc < 10; tc++)
	{
		scanf("%d", &tcase);		
		init();

		int num;
		for (int i = 0; i < 1000; i++)
		{
			scanf("%d", &num);
			nums[num]++;
		}

		int max = 0;
		int ans;
		for (int j = 0; j < 101; j++)
		{
			if (max <= nums[j])
			{
				max = nums[j];
				ans = j;
			}
		}

		printf("#%d %d\n", tcase, ans);

	}	

	return 0;
}


void init()
{
	for (int i = 0; i < 101; i++)
	{
		nums[i] = 0;
	}
}