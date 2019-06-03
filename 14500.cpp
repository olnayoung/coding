#include <iostream>

int M, N, max = 0;
int map[500][500];
int sum;

int ter() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (x + 3 < M) {
				sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y][x + 3];
				max = (sum > max) ? sum : max;
			}
			if (y + 3 < N) {
				sum = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 3][x];
				max = (sum > max) ? sum : max;
			} // 1

			if ((y + 1 < N) && (x + 1 < M)) {
				sum = map[y][x] + map[y + 1][x] + map[y][x + 1] + map[y + 1][x + 1];
				max = (sum > max) ? sum : max;
			} // 2

			if ((y + 2 < N) && (x + 1 < M)) {
				sum = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 2][x + 1];
				max = (sum > max) ? sum : max;

				sum = map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1];
				max = (sum > max) ? sum : max;

				sum = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x + 1];
				max = (sum > max) ? sum : max;

				sum = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x];
				max = (sum > max) ? sum : max;

				sum = map[y + 1][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x + 1];
				max = (sum > max) ? sum : max;

				sum = map[y][x + 1] + map[y + 1][x + 1] + map[y + 2][x] + map[y + 2][x + 1];
				max = (sum > max) ? sum : max;

				sum = map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y][x + 1];
				max = (sum > max) ? sum : max;

				sum = map[y][x + 1] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x];
				max = (sum > max) ? sum : max;
			}

			if ((y + 1 < N) && (x + 2 < M)) {
				sum = map[y][x + 2] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2];
				max = (sum > max) ? sum : max;

				sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x];
				max = (sum > max) ? sum : max;

				sum = map[y][x + 1] + map[y][x + 2] + map[y + 1][x] + map[y + 1][x + 1];
				max = (sum > max) ? sum : max;

				sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1];
				max = (sum > max) ? sum : max;

				sum = map[y][x + 1] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2];
				max = (sum > max) ? sum : max;

				sum = map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 2];
				max = (sum > max) ? sum : max;

				sum = map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 1][x + 2];
				max = (sum > max) ? sum : max;

				sum = map[y][x] + map[y][x + 1] + map[y + 1][x + 1] + map[y + 1][x + 2];
				max = (sum > max) ? sum : max;
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	ter();

	printf("%d", max);

	return 0;
}
