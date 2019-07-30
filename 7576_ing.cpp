#include <iostream>
#include <queue>
#define len 1002

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

			if ((new_y > -1) && (new_y < H) && (new_x > -1) && (new_x < W) && (map[new_y][new_x] == 0) && (visit[y][x] + 1 < visit[new_y][new_x])) {
				que_y.push(new_y);	que_x.push(new_x);
				visit[new_y][new_x] = visit[y][x] + 1; 
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d %d", &W, &H);

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 1) {
				que_y.push(y);	que_x.push(x);
				visit[y][x] = 0;
			}
			else	visit[y][x] = len*100;
		}
	}

	BFS();

	ans = 0;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if ((visit[h][w] == (len * 100)) && (map[h][w] == -1)) continue;
			ans = (ans > visit[h][w]) ? ans : visit[h][w];
		}
	}

	if (ans == (len * 100))	ans = -1;

	printf("%d", ans);

	return 0;
}
