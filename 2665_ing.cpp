#include <cstdio>

int N, min;
int map[50][50], dist[50][50], visit[50][50];
int que[9999999][2];
int start, finish;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int clear() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			dist[y][x] = 200;
		}
	}
	return 0;
}

int walls() {
	que[finish][0] = 0;	que[finish][1] = 0;
	finish++;
	dist[0][0] = 0;

	int y, x, new_y, new_x;
	while (start < finish) {
		y = que[start][0];	x = que[start][1];
		start++;

		for (int t = 0; t < 4; t++) {
			new_y = y + dy[t];	new_x = x + dx[t];
			
			if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N)) {
				que[finish][0] = new_y;	que[finish][1] = new_x;
				finish++;

				if (map[new_y][new_x] == 1) {
					dist[new_y][new_x] = (dist[y][x] < dist[new_y][new_x]) ? dist[y][x] : dist[new_y][new_x];
				}
				else {
					dist[new_y][new_x] = (dist[y][x] + 1 < dist[new_y][new_x]) ? dist[y][x] + 1 : dist[new_y][new_x];
				}
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%1d", &map[y][x]);
		}
	}

	clear();
	walls();
	printf("%d", dist[N-1][N-1]);

	return 0;
}
