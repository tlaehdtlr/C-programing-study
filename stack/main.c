#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void push(int* stack[], int num, int* idx)
{
	stack[*idx] = num;
	*idx += 1;
}

int pop(int* stack[], int* idx)
{
	if (*idx == 0) return -1;
	*idx -= 1;
	int out = stack[*idx];
	stack[*idx] = 0;

	return out;
}

int size(int* stack[], int* idx)
{
	return *idx;
}

int empty(int* stack[], int* idx)
{
	if (*idx == 0) return 1;
	return 0;
}

int top(int* stack[], int* idx)
{
	if (*idx == 0) return -1;
	return stack[*idx - 1];
}


int main()
{
	int N;
	scanf("%d", &N);
	char command[10];
	int* stack = malloc(sizeof(int) * N);
	int zero = 0;
	int* idx = &zero;


	int num;
	for (int i = 0; i < N; i++)
	{
		scanf("%s", command);

		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &num);
			push(stack, num, idx);
		}
		else if (strcmp(command, "pop") == 0)
		{
			printf("%d\n", pop(stack, idx));
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", size(stack, idx));
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", empty(stack, idx));
		}
		else if (strcmp(command, "top") == 0)
		{
			printf("%d\n", top(stack, idx));
		}
	}

	return 0;
}