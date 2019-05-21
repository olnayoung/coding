#include <iostream>

int hei, wid;
int map[8][8];
int visit[8][8];
int num, max = 0, num_of_cctv;
int h[8], w[8], n[8];

int clear() {
	for (int y = 0; y < hei; y++) {
		for (int x = 0; x < wid; x++) {
			visit[y][x] = 0;
		}
	}

	return 0;
}

int count() {
	num = 0;
	for (int y = 0; y < hei; y++) {
		for (int x = 0; x < wid; x++) {
			if (visit[y][x] == 1) num++;
		}
	}

	max = (max > num) ? max : num;

	return 0;
}

int up(int j, int i) {
	for (int y = j-1; y > -1; y--) {
		if (map[y][i] != 0) break;
		visit[y][i] = 1;
	}

	return 0;
}

int down(int j, int i) {
	for (int y = j + 1; y < hei; y++) {
		if (map[y][i] != 0) break;
		visit[y][i] = 1;
	}

	return 0;
}

int left(int j, int i) {
	for (int x = 1 - 1; x > -1; x--) {
		if (map[j][x] != 0) break;
		visit[j][x] = 1;
	}

	return 0;
}

int right(int j, int i) {
	for (int x = i + 1; x < hei; x++) {
		if (map[j][x] != 0) break;
		visit[j][x] = 1;
	}

	return 0;
}

int cctv(int repeat) {
	if (repeat == num_of_cctv) count();

	if (n[repeat] == 1) {
		up(h[repeat], w[repeat]);
		cctv(repeat + 1);
	}

	return 0;
}

int main() {
	scanf("%d %d", &hei, &wid);

	for (int y = 0; y < hei; y++) {
		for (int x = 0; x < wid; x++) {
			scanf("%d", &map[y][x]);
			if ((map[y][x] > 0) && (map[y][x] < 6)) num_of_cctv++;
		}
	}

	return 0;
}
