#include <iostream>

int hei, wid;
int r, c, w;
int count = 0, check = 0;
int map[50][50];
int visit[50][50];
int direc[4] = { 0, 1, 2, 3 };
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int left_dx[4] = {-1, 0, 1, 0};
int left_dy[4] = {0, -1, 0, 1};


int clean(int r, int c, int w, int check) {
	if ((map[r][c] == 0) && (visit[r][c] == 0)) {
		visit[r][c] = 1;
		count++;
	}

	for (int t = 0; t < 4; t++) {
		if (w == direc[t]) { // 현재 방향 찾기
			if (check == 4) {
				if ((r + dy[t] > -1) && (r + dy[t] < hei) && (c + dx[t] > -1) && (c + dx[t] < wid) && (map[r + dy[t]][c + dx[t]] == 0)) {
					clean(r + dy[t], c + dx[t], w, 0);
				}
				else {
					printf("%d", count);
					exit(0);
				}
			}

			if ((r + left_dy[t] > -1) && (r + left_dy[t] < hei) && (c + left_dx[t] > -1) && (c + left_dx[t] < wid)) { // map 내부인지 확인
				w = (w + 3) % 4;
				if ((visit[r + left_dy[t]][c + left_dx[t]] == 0) && (map[r + left_dy[t]][c + left_dx[t]] == 0)) clean(r + left_dy[t], c + left_dx[t], w, 0);
				else clean(r, c, w, check + 1);

			}
			else clean(r, c, (w + 3) % 4, check + 1);
		}
	}

	return 0;
}

int main() {
	scanf("%d %d", &hei, &wid);
	scanf("%d %d %d", &r, &c, &w);

	for (int y = 0; y < hei; y++) {
		for (int x = 0; x < wid; x++) {
			scanf("%d", &map[y][x]);
			visit[y][x] = 0;
		}
	}

	clean(r, c, w, check);

	return 0;
}
