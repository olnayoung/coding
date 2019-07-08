#include<iostream>

int N, max;
int map[550][550];

int main() {
	scanf("%d", &N);

	for (int y = 1; y < N+1; y++) {
		for (int x = 1; x < y+1; x++) {
			scanf("%d", &map[y][x]);
			map[y][x] = (map[y - 1][x] > map[y - 1][x - 1]) ? map[y][x] + map[y - 1][x] : map[y][x] + map[y - 1][x - 1];
		}
	}

	for (int x = 1; x < N + 1; x++) {
		max = (max > map[N][x]) ? max : map[N][x];
	}

	printf("%d", max);

	return 0;
}
