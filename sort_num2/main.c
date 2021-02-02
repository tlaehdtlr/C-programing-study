#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int L[10000], R[10000];
int merge(long long int arr[], int l1, int l2, int r1, int r2)
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


int merge_sort(long long int arr[], int st, int end)
{
	if (st < end)
	{
		int mid = (st + end) / 2;
		merge_sort(arr, st, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, st, mid, mid + 1, end);
	}
	return 0;
}


int main()
{
	int N;
	scanf("%d", &N);

	long long int arr[10000] = { 0 };
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	merge_sort(arr, 0, N - 1);
	
	for (int i = 0; i < N; i++) printf("%d\n", arr[i]);

	return 0;
}