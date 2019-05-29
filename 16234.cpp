#include <iostream>
#define MAX 9999999

int N, L, R, n_group, num, check, num_moved;
int map[55][55], group[4000][2][4000];
int visit[55][55], numbers[4000];
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

int move() {
	for (int m = 0; m < n_group; m++) {
		int sum = 0;
		for (int n = 0; n < numbers[m]; n++) {
			sum += map[group[m][0][n]][group[m][1][n]];
		}

		if (numbers[m] == 0) continue;
		sum = sum / numbers[m];

		for (int n = 0; n < numbers[m]; n++) {
			map[group[m][0][n]][group[m][1][n]] = sum;
		}
	}
	num_moved++;
	//print();

	return 0;
}

int open(int y, int x) {
	if (visit[y][x] == 1)	return 0;

	visit[y][x] = 1;
	group[n_group][0][num] = y;		group[n_group][1][num] = x;
	num++;

	for (int t = 0; t < 4; t++) {
		int new_y, new_x, diff;
		new_y = y + dy[t];	new_x = x + dx[t];

		diff = map[y][x] - map[new_y][new_x];
		diff = (diff > 0) ? diff : -diff;

		if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N) && (visit[new_y][new_x] == 0) && (diff >= L) && (diff <= R)) {
			check = 1;
			open(new_y, new_x);
		}
	}
	return 0;
}

int main() {
	scanf("%d %d %d", &N, &L, &R);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	check = 1;
	while (check == 1) {
		check = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				open(y, x);
				numbers[n_group] = num;
				n_group++;
				num = 0;
			}
		}
		move();
		clear();
		n_group = 0;	num = 0;
	}

	printf("%d", num_moved-1);

	return 0;
}
