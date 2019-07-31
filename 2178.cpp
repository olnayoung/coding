#include <iostream>
#include <queue>
#define len 101

using namespace std;

int H, W, ans;
int map[len][len], visit[len][len];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<int> que_y, que_x;

int BFS() {
	int y, x, new_y, new_x;
	while (que_y.size() != 0) {
		y = que_y.front();	que_y.pop();
		x = que_x.front();	que_x.pop();

		for (int t = 0; t < 4; t++) {
			new_y = y + dy[t];	new_x = x + dx[t];

			if ((new_y > -1) && (new_y < H) && (new_x > -1) && (new_x < W) && (map[new_y][new_x] == 1) && (visit[new_y][new_x] == 0)) {
				que_y.push(new_y);	que_x.push(new_x);
				visit[new_y][new_x] = visit[y][x] + 1; 
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d %d", &H, &W);

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	visit[0][0] = 1;

	que_y.push(0);	que_x.push(0);

	BFS();

	printf("%d", visit[H - 1][W - 1]);

	return 0;
}
