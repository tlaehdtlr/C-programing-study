#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bigger(int** h, int cur, int n)
{
    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        if (h[i][0] > h[cur][0] && h[i][1] > h[cur][1]) rank += 1;
    }

    return rank;
}


int main()
{
    int n;
    scanf("%d", &n);

    int** human = (int*)malloc(sizeof(int*) * n);

    int w, h, r;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w, &h);

        human[i] = (int*)malloc(sizeof(int) * 3);
        human[i][0] = w;
        human[i][1] = h;
    }

    for (int i = 0; i < n; i++) human[i][2] = bigger(human, i, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", human[i][2]);
    }
    printf("\n");


    return 0;
}
