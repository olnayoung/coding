#include <iostream>
#define MAX 9999999

int N, L, R, n_group;
int map[50][50], group[2500][2][2500];
int visit[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int print() {
	printf("\n\n");
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}
	return 0;
}

int clear() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			visit[y][x] = 0;
		}
	}
	return 0;
}

int open(int y, int x) {
	for (int t = 0; t < 4; t++) {
		int new_y, new_x;
		new_y = y + dy[t];	new_x = x + dx[t];

		if ((new_y > -1) && (new_y < N) && (new_x > -1)  && (new_x < N) && (visit[y][x] == 0)) {
			visit[y][x] = 1;
			open(new_y, new_x);
		}
	}

	return 0;
}

int main() {
	scanf("%d %d %d", &N, &L, &R);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", map[y][x]);
		}
	}

	return 0;
}
