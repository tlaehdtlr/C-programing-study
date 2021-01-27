#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fly[15][15] = { 0 };
void init();

int main() {
	int T = 0;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int N=0, M=0;
		scanf("%d %d", &N, &M);				
		
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &fly[i][j]);
			}
		}

		int ans = 0;
		for (int i = 0; i < N-M+1; i++) {
			for (int j = 0; j < N-M+1; j++) {
				int cnt = 0;
				for (int a = 0; a < M; a++) {
					for (int b = 0; b < M; b++) {
						cnt += fly[i+a][j+b];
					}
				}
				if (ans < cnt) ans = cnt;
			}
		}
		printf("#%d %d\n", tc, ans);
	}

	return 0;
}

void init() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			fly[i][j] = 0;
		}
	}
}