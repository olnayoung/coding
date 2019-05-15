#include <iostream>

int K;
int n, d;
int map[4][8];

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
