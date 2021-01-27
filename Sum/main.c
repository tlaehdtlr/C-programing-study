#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   
void input_value(int** arr, int row, int col);
void clear_arr(int** arr, int row, int col);
int sum_row(int** arr, int row, int col);
int sum_col(int** arr, int row, int col);
int sum_x(int** arr, int row, int col);

inline int MAX(int a, int b) {
	return a > b ? a : b;
}


int main(void)
{		
	int row = 100, col = 100;	
	int** arr = malloc(sizeof(int*) * row);

	for (int i = 0; i < row; i++)
	{
		arr[i] = malloc(sizeof(int) * col);
	}

	for (int tc = 1; tc <= 1; tc++)
	{
		int _tc = 0;
		scanf("%d", &_tc);
		clear_arr(arr, row, col);

		input_value(arr, row, col);
		
		int ans = 0;		
		ans = MAX(ans,sum_row(arr, row, col));				
		ans = MAX(ans, sum_col(arr, row, col));		
		ans = MAX(ans, sum_x(arr, row, col));
		
		printf("#%d %d\n", _tc, ans);

	}

	for (int i = 0; i < row; i++)
	{
		free(arr[i]);
	}

	free(arr);

	return 0;
}

void input_value(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
}


void clear_arr(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = 0;
		}
	}
}


int sum_row(int** arr, int row, int col)
{
	int ans = 0;
	for (int i = 0; i < row; i++)
	{
		int cnt = 0;
		for (int j = 0; j < col; j++)
		{
			cnt += arr[i][j];
		}
		ans = MAX(ans, cnt);
	}
	return ans;
}

int sum_col(int** arr, int row, int col)
{
	int ans = 0;
	for (int i = 0; i < row; i++)
	{
		int cnt = 0;
		for (int j = 0; j < col; j++)
		{
			cnt += arr[j][i];
		}
		ans = MAX(ans, cnt);
	}
	return ans;
}

int sum_x(int** arr, int row, int col)
{
	int ans = 0, cnt =0;
	for (int i = 0; i < row; i++)
	{
		cnt += arr[i][i];
		ans = MAX(ans, cnt);
	}

	cnt = 0;
	for (int i = 0; i < row; i++)
	{
		cnt += arr[i][row-i];
		ans = MAX(ans, cnt);
	}

	return ans;
}

