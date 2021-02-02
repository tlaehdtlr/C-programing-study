https://www.acmicpc.net/problem/2751



```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int* root = (int*)malloc(sizeof(int) * N * 2);

	int* input = root;
	int* output = &input[N];
	for (int i = 0; i < N; ++i)
	{
		int numb;
		scanf("%d", &numb);

		input[i] = numb + 1000000;
	}

	int keyindex = 0;
	int key_compare[4];
	key_compare[0] = 0xFF;
	key_compare[1] = 0xFF00;
	key_compare[2] = 0xFF0000;
	key_compare[3] = 0x7F000000;
	while (keyindex < 4)
	{
		int key = key_compare[keyindex];
		int temp[0xFF + 1] = { 0, };

		for (int i = 0; i < N; ++i)
		{
			int keyvalue = input[i] & key;

			int movekey = 0;
			while (movekey < keyindex)
			{
				keyvalue >>= 8;
				++movekey;
			}

			temp[keyvalue] += 1;
		}

		for (int i = 1; i <= 0xFF; ++i)
			temp[i] = temp[i] + temp[i - 1];

		for (int i = N - 1; i >= 0; --i)
		{
			int keyvalue = input[i] & key;
			int movekey = 0;
			while (movekey < keyindex)
			{
				keyvalue >>= 8;
				++movekey;
			}

			output[temp[keyvalue] - 1] = input[i];
			temp[keyvalue] -= 1;
		}

		++keyindex;
		int* tempptr = input;
		input = output;
		output = tempptr;
	}

	for (int i = 0; i < N; ++i) printf("%d\n", input[i] - 1000000);
	free(root);

	return 0;
}
```



```c
#include <stdio.h>
#define MAX 1000000
#define gc getchar_unlocked

void scan_int(int *x)
{
    register int c = gc();
    *x = 0;
    int neg = 0;
    for( ; ((c<48 || c>57) && c != '-'); c = gc() );
    if( c=='-' ) {
        neg=1;
        c=gc();
    }
    for( ;c>47 && c<58; c = gc() ) {
        *x = (*x << 1) + (*x << 3) + c - 48;
    }
    if( neg )
        *x=-*x;
} 
int vals[2 * MAX + 1] = {0};

int main(void)
{
  int cnt;
  int n;
  int i;
  scan_int(&cnt);


  for (i = 0; i < cnt; i++) {
    scan_int(&n);
    vals[n+MAX] = 1;
  }
  for (i = 0; i < 2 * MAX + 1; i++) {
    if (vals[i])
      printf("%d\n", i - MAX);
  }

  
  return 0;
}

```

