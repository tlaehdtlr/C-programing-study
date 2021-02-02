#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int merge(int arr[], int L[], int R[], int l1, int l2, int r1, int r2)
{	
	int i = 0;
	l2++;
	r2++;
	
	for (int i = l1; i < l2; i++) L[i] = arr[i];
	for (int i = r1; i < r2; i++) R[i] = arr[i];

	int idx = l1;
	while (l1 < l2 && r1 < r2)
	{
		if (L[l1] > R[r1])
		{
			arr[idx] = R[r1];
			idx++;
			r1++;
		}
		else
		{
			arr[idx] = L[l1];
			idx++;
			l1++;
		}
	}

	if (l1 < l2)
	{
		while (l1 < l2)
		{
			arr[idx] = L[l1];
			idx++;
			l1++;
		}
	}
	else
	{
		while (r1 < r2)
		{
			arr[idx] = R[r1];
			idx++;
			r1++;
		}
	}	
	return 0;
}


int merge_sort(int arr[], int L[], int R[], int st, int end)
{
	if (st < end)
	{
		int mid = (st + end) / 2;
		merge_sort(arr, L, R, st, mid);
		merge_sort(arr, L, R, mid + 1, end);
		merge(arr, L, R, st, mid, mid + 1, end);
	}
	return 0;
}


int main()
{
	int N;
	scanf("%d", &N);

	int* human = (int*)malloc(sizeof(int) * N);
	int* L = (int*)malloc(sizeof(int) * N);
	int* R = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++) scanf("%d", &human[i]);
	for (int i = 0; i < N; i++) L[i] = 0;
	for (int i = 0; i < N; i++) R[i] = 0;

	merge_sort(human, L, R, 0, N - 1);
	
	for (int i = 0; i < N; i++) printf("%d\n", human[i]);

	free(human);
	free(L);
	free(R);

	return 0;
}