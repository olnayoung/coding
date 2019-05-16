#include <iostream>

int N;
int map[15][2];

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		scanf("%d %d", &map[y][0], &map[y][1]);
	}

	return 0;
}
