#include <stdio.h>

int main() {

	int num, ans;
	int T = 0;
	scanf_s("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		num = 0, ans = 0 ;
		for (int i = 0; i < 10; i++) {
			scanf_s("%d", &num);
			if (num & 1) ans += num;
		}
		printf("#%d %d\n", tc, ans);
	}	
	return 0;
}