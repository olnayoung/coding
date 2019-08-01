#include <iostream>
#include <queue>
#define len 101
#define big 100000

using namespace std;

int N, number, minimum = big;
int map[len][len], island[len][len], dist[len][len];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<int> que_y, que_x;

int length() {
	for (int n = 1; n <= number; n++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				dist[y][x] = big;
				if (island[y][x] == n) {
					que_y.push(y);	que_x.push(x);
					dist[y][x] = 0;
				}
			}
		}

		int y, x, new_y, new_x;
		while (que_y.size() != 0) {
			y = que_y.front();	que_y.pop();
			x = que_x.front();	que_x.pop();

			for (int t = 0; t < 4; t++) {
				new_y = y + dy[t];	new_x = x + dx[t];

				if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N) && (dist[new_y][new_x] > dist[y][x] + 1)) {
					if (map[new_y][new_x] == 0) {
						que_y.push(new_y);	que_x.push(new_x);
						dist[new_y][new_x] = dist[y][x] + 1;
					}
					else if (island[new_y][new_x] == n) {
						que_y.push(new_y);	que_x.push(new_x);
					}
					else if (island[new_y][new_x] != n) {
						dist[new_y][new_x] = dist[y][x] + 1;
					}
				}
			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if ((map[y][x] == 1) && (island[y][x] != n))
					minimum = (minimum < dist[y][x]) ? minimum : dist[y][x];
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

			if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N) && (map[new_y][new_x] == 1) && (island[new_y][new_x] == 0)) {
				que_y.push(new_y);	que_x.push(new_x);
				island[new_y][new_x] = number;
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

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if ((map[y][x] == 1) && (island[y][x] == 0)) {
				number++;
				island[y][x] = number;
				BFS(y, x);
			}
		}
	}

	length();

	printf("%d", minimum - 1);

	return 0;
}
