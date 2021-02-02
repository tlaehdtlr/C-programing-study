#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int nums[1000];

int bubble_sort(int n)
{
    for (int i = n - 1; i > -1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int num = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = num;
            }
        }
    }
}


int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
    bubble_sort(N);

    for (int i = 0; i < N; i++) printf("%d\n", nums[i]);

    return 0;
}