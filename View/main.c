#include <stdio.h>

int buildings[1001] = { 0 };
void init();
int view(int num);


int main() {	
	/*FILE* input;
	input = fopen("input.txt", "r");*/
	for (int tc = 1; tc <= 10; tc++) {
		int L_col = 0, building = 0, ans = 0;
		scanf_s("%d", &L_col);
		init();
		for (int i = 0; i < L_col; i++) {
			scanf_s("%d", &building);
			buildings[i] = building;
		}

		for (int num = 2; num < L_col - 2; num++) {
			ans += view(num);
		}		

		printf("#%d %d\n", tc, ans);
	}

	return 0;
}


void init() {
	for (int i = 0; i < 1001; i++) {
		buildings[i] = 0;
	}
}


int view(int num) {
	int tmp = 0, min=255;
	for (int i = -2; i <= 2; i++) {
		if (i != 0) {
			tmp = buildings[num] - buildings[num + i];
			if (tmp <= 0) {
				return 0;
			}
			else {
				if (min > tmp) {
					min = tmp;
				}
			}
		}
	}
	return min;
}