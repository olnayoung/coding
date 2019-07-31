#include <iostream>
#include <queue>
#define len 101

using namespace std;

int N, number, minimum, dist[len][len], dist_y, dist_x;
int map[len][len], visit[len][len];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<int> que_y, que_x;

int length() {
	int y, x, new_y, new_x;
	while (que_y.size() != 0) {
		y = que_y.front();	que_y.pop();
		x = que_x.front();	que_x.pop();

		for (int t = 0; t < 4; t++) {
			new_y = y + dy[t];	new_x = x + dx[t];

			if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N) && (visit[new_y][new_x] != visit[y][x]) && (visit[new_y][new_x] > 0)) {
				que_y.push(new_y);	que_x.push(new_x);
				dist_y = (new_y > y) ? new_y - y : y - new_y;
				dist_x = (new_x > x) ? new_x - x : x - new_x;
				dist[new_y][new_x] = (dist[new_y][new_x] < dist_y + dist_x) ? dist[new_y][new_x] : dist_y + dist_x;
			}
		}
	}

	return 0;
}

int BFS(int h, int w) {
	que_y.push(h);	que_x.push(w);

	int y, x, new_y, new_x;
	while (que_y.size() != 0) {
		y = que_y.front();	que_y.pop();
		x = que_x.front();	que_x.pop();

		for (int t = 0; t < 4; t++) {
			new_y = y + dy[t];	new_x = x + dx[t];

			if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N) && (map[new_y][new_x] == 1) && (visit[new_y][new_x] == 0)) {
				que_y.push(new_y);	que_x.push(new_x);
				visit[new_y][new_x] = number;
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

	minimum = N * 2;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if ((map[y][x] == 1) && (visit[y][x] == 0)) {
				number++;
				BFS(y, x);
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visit[y][x] > 0) {
				que_y.push(y);	que_x.push(x);
			}
		}
	}

	length();

	printf("%d", minimum);

	return 0;
}
