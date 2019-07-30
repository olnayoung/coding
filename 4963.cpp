#include <iostream>
#include <queue>
#define len 51

using namespace std;

int H, W, ans;
int map[len][len], visit[len][len];
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
queue<int> que_y, que_x;

int BFS(int h, int w) {
	que_y.push(h);	que_x.push(w);

	int y, x, new_y, new_x;
	while (que_y.size() != 0) {
		y = que_y.front();	x = que_x.front();
		que_y.pop();	que_x.pop();
		visit[y][x] = 1;

		for (int t = 0; t < 8; t++) {
			new_y = y + dy[t];	new_x = x + dx[t];

			if ((new_y > -1) && (new_y < H) && (new_x > -1) && (new_x < W) && (visit[new_y][new_x] == 0) && (map[new_y][new_x] == 1)) {
				que_y.push(new_y);	que_x.push(new_x);
				visit[new_y][new_x] = 1;
			}
		}
	}

	return 0;
}

int main() {
	while (1) {
		scanf("%d %d", &W, &H);

		if ((H == 0) && (W == 0))	return 0;

		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				visit[y][x] = 0;
				scanf("%d", &map[y][x]);
			}
		}

		ans = 0;
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				if ((visit[h][w] == 0) && (map[h][w] == 1)) {
					BFS(h, w);
					ans++;
				}
			}
		}

		printf("%d\n", ans);

	}

	return 0;
}
