#include <cstdio>
#define max 9999999

int N, M, min = 70, count_w, count_b;
char map[50][50];
int start_y, start_x;

int print() {
	printf("\n"); printf("\n");
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%c ", map[y][x]);
		}
		printf("\n");
	}
	return 0;
}

int check() {
	count_w = 0;	count_b = 0;

	for (int y = start_y; y < start_y + 8; y++) {
		for (int x = start_x; x < start_x + 8; x++) {
			if ((x + y) % 2 == 0) {
				if (map[y][x] == 'W') {
					count_b++;
				}
				else {
					count_w++;
				}
			}
			else {
				if (map[y][x] == 'W') {
					count_w++;
				}
				else {
					count_b++;
				}
			}
		}
	}

	min = (min < count_w) ? min : count_w;
	min = (min < count_b) ? min : count_b;

	return 0;
}

int search() {
	for (int y = 0; y < N - 7; y++) {
		for (int x = 0; x < M - 7; x++) {
			start_y = y; start_x = x;
			check();
		}
	}
	return 0;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int y = 0; y < N; y++) {
		getchar();
		for (int x = 0; x < M; x++) {
			scanf("%c", &map[y][x]);
		}
	}

	search();

	printf("%d", min);

	return 0;
}
