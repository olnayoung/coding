#include <iostream>
#define MAX 9999999

int N, h, w, size = 2, eaten;
int map[20][20];
int visit[20][20];
int que_y[MAX], que_x[MAX], que_d[MAX];
int start, finish, time, dist[20][20];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

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

int find_fish() {
	while (start < finish) {
		int y = que_y[start];
		int x = que_x[start];
		start++;

		if ((map[y][x] < size) && (map[y][x] > 0)) {
			map[y][x] = 0;
			eaten++;

			time += dist[y][x];

			start = 0;
			que_y[0] = y;	que_x[0] = x;	que_d[0] = 0;
			finish = 1;
			clear();
			dist[y][x] = 0;

			if (eaten == size) {
				eaten = 0;	size++;
			}

			find_fish();
		}

		for (int t = 0; t < 4; t++) {
			int new_y, new_x;
			new_y = y + dy[t];	new_x = x + dx[t];

			if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N) && (visit[new_y][new_x] == 0) && (map[new_y][new_x] < size + 1)) {
				visit[y][x] = 1;
				que_y[finish] = new_y;	que_x[finish] = new_x;
				dist[new_y][new_x] = (dist[new_y][new_x] < dist[y][x] + 1) ? dist[new_y][new_x] : dist[y][x] + 1;
				finish++;
			}
		}
	}

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
				que_y[finish] = h;	que_x[finish] = w;
				finish++;
			}
		}
	}

	clear();
	dist[h][w] = 0;
	find_fish();

	printf("%d", time);

	return 0;
}
