#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Queue
{
	int last;
	int* arr;
} Queue;


int main()
{
	int N;
	scanf("%d", &N);
	Queue que;
	que.arr = (int*)malloc(sizeof(int) * N);

	char command[6];
	int input_num;


	return 0;
}