#include <iostream>
#define MAX 9999999

int N, h, w, size = 2, eaten;
int map[20][20];
int visit[20][20];
int que[3][MAX], pos[3][MAX];
int start, finish, pos_finish, time, dist[20][20];
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

int eat();

int print() {
	printf("\n\n");
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%d ", dist[y][x]);
		}
		printf("\n");
	}
	return 0;
}

int clear() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			visit[y][x] = 0;
			dist[y][x] = 999;
		}
	}
	return 0;
}

int sort() {
	if (pos_finish > 1) {
		for (int a = 0; a < pos_finish; a++) {
			for (int b = 0; b < pos_finish - 1; b++) {
				if (pos[2][b] > pos[2][b + 1]) {
					int temp = pos[2][b + 1];	pos[2][b + 1] = pos[2][b];	pos[2][b] = temp;
					temp = pos[1][b + 1];	pos[1][b + 1] = pos[1][b];	pos[1][b] = temp;
					temp = pos[0][b + 1];	pos[0][b + 1] = pos[0][b];	pos[0][b] = temp;
				}
			}
		}

		int n = 0;
		while (pos[2][n] == pos[2][n + 1]) n++;
		n++;

		if (n > 1) {
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n - 1; b++) {
					if (pos[0][b] > pos[0][b + 1]) {
						int temp = pos[2][b + 1];	pos[2][b + 1] = pos[2][b];	pos[2][b] = temp;
						temp = pos[1][b + 1];	pos[1][b + 1] = pos[1][b];	pos[1][b] = temp;
						temp = pos[0][b + 1];	pos[0][b + 1] = pos[0][b];	pos[0][b] = temp;
					}
				}
			}

			int m = 0;
			while ((pos[0][m] == pos[0][m + 1]) && (m <= n)) m++;
			m++;

			if (m > 1) {
				for (int a = 0; a < m; a++) {
					for (int b = 0; b < m - 1; b++) {
						if (pos[1][b] > pos[1][b + 1]) {
							int temp = pos[2][b + 1];	pos[2][b + 1] = pos[2][b];	pos[2][b] = temp;
							temp = pos[1][b + 1];	pos[1][b + 1] = pos[1][b];	pos[1][b] = temp;
							temp = pos[0][b + 1];	pos[0][b + 1] = pos[0][b];	pos[0][b] = temp;
						}
					}
				}
			}

		}
	}

	eat();
	return 0;
}

int find_fish() {
	while (start < finish) {
		int y = que[0][start];
		int x = que[1][start];
		start++;

		for (int t = 0; t < 4; t++) {
			int new_y, new_x;
			new_y = y + dy[t];	new_x = x + dx[t];

			if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N) && (visit[new_y][new_x] == 0) && (map[new_y][new_x] < size + 1)) {
				visit[new_y][new_x] = 1;
				que[0][finish] = new_y;	que[1][finish] = new_x;
				dist[new_y][new_x] = (dist[new_y][new_x] < dist[y][x] + 1) ? dist[new_y][new_x] : dist[y][x] + 1;
				finish++;
				if ((map[new_y][new_x] > 0) && (map[new_y][new_x] < size)) {
					pos[0][pos_finish] = new_y;	pos[1][pos_finish] = new_x;	pos[2][pos_finish] = dist[new_y][new_x];
					pos_finish++;
				}
			}
		}
	}

	if (pos_finish > 0)	sort();
	else printf("%d", time);

	return 0;
}

int eat() {
	map[pos[0][0]][pos[1][0]] = 0;
	eaten++;
	time += dist[pos[0][0]][pos[1][0]];
	clear();
	dist[pos[0][0]][pos[1][0]] = 0;

	if (eaten == size) {
		eaten = 0;	size++;
	}

	que[0][0] = pos[0][0];	que[1][0] = pos[1][0];
	start = 0;	finish = 1;

	pos_finish = 0;
	find_fish();
	return 0;
}

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 9) {
				h = y;	w = x;
				visit[y][x] = 1;
				que[0][finish] = h;	que[1][finish] = w;
				map[y][x] = 0;
				finish++;
			}
		}
	}

	clear();
	dist[h][w] = 0;
	find_fish();

	return 0;
}
