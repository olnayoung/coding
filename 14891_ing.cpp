#include <iostream>

int K;
int n, d;
int map[4][8];

int clock(int x) {
	int temp = map[x][7];

	for (int t = 0; t < 7; t++) {
		map[x][t+1] = map[x][t];
	}

	map[x][0] = map[x][7];

	return 0;
}

int counter_clock(int x) {
	int temp = map[x][0];

	for (int t = 0; t < 7; t++) {
		map[x][t] = map[x][t+1];
	}

	map[x][7] = map[x][0];

	return 0;
}

int main() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 8; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	scanf("%d", &K);

	for (int t = 0; t < K; t++) {
		scanf("%d %d", &n, &d);

		
	}

	return 0;
}
