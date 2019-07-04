#include<iostream>
#define max 999999

int N, ans;
int map[2][50], temp;

int sort() {
	for (int y = N - 1; y > 0; y--) {
		for (int x = 0; x < y; x++) {
			if (map[0][x] > map[0][x + 1]) {
				temp = map[0][x + 1];
				map[0][x + 1] = map[0][x];
				map[0][x] = temp;
			}
			if (map[1][x] < map[1][x + 1]) {
				temp = map[1][x + 1];
				map[1][x + 1] = map[1][x];
				map[1][x] = temp;
			}
		}
	}

	return 0;
}

int calcul() {
	for (int t = 0; t < N; t++) {
		ans = ans + map[0][t] * map[1][t];
	}
	return 0;
}

int main(){
	scanf("%d", &N);

	for (int y = 0; y < 2; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	sort();
	calcul();

	printf("%d", ans);

	return 0;
}
