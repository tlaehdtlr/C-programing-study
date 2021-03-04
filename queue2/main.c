#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
	int val[10000];
	int pre;
	int last;
	int size;
} Queue;



void push(Queue* q, int num)
{
	q->last++;
	q->val[q->last] = num;
	// ¿©±â ´õ ¼ÕºÁ
}


int main()
{
	int N;
	scanf("%d", &N);
	Queue que;
	que.size = 10000 - 1;
	char command[6];
	int* input_num;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &input_num);
			push(&que, input_num);
		}
	}


	return 0;
}