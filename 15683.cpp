#include <iostream>

int hei, wid;
int map[8][8];
int visit[8][8];
int num, min = 64, num_of_cctv;
int h[8], w[8], n[8];

int count() {
	num = 0;
	for (int y = 0; y < hei; y++) {
		for (int x = 0; x < wid; x++) {
			if (visit[y][x] == 0) num++;
		}
	}

	min = (min < num) ? min : num;

	return 0;
}

int up(int j, int i) {
	for (int y = j - 1; y > -1; y--) {
		if (map[y][i] == 6) break;
		visit[y][i] += 1;
	}

	return 0;
}

int down(int j, int i) {
	for (int y = j + 1; y < hei; y++) {
		if (map[y][i] == 6) break;
		visit[y][i] += 1;
	}

	return 0;
}

int left(int j, int i) {
	for (int x = i - 1; x > -1; x--) {
		if (map[j][x] == 6) break;
		visit[j][x] += 1;
	}

	return 0;
}

int right(int j, int i) {
	for (int x = i + 1; x < wid; x++) {
		if (map[j][x] == 6) break;
		visit[j][x] += 1;
	}

	return 0;
}

int up_re(int j, int i) {
	for (int y = j - 1; y > -1; y--) {
		if (map[y][i] == 6) break;
		visit[y][i] -= 1;
	}

	return 0;
}

int down_re(int j, int i) {
	for (int y = j + 1; y < hei; y++) {
		if (map[y][i] == 6) break;
		visit[y][i] -= 1;
	}

	return 0;
}

int left_re(int j, int i) {
	for (int x = i - 1; x > -1; x--) {
		if (map[j][x] == 6) break;
		visit[j][x] -= 1;
	}

	return 0;
}

int right_re(int j, int i) {
	for (int x = i + 1; x < wid; x++) {
		if (map[j][x] == 6) break;
		visit[j][x] -= 1;
	}

	return 0;
}

int cctv(int repeat) {
	if (repeat == num_of_cctv) {
		count();
		return 0;
	}

	if (n[repeat] == 1) {
		up(h[repeat], w[repeat]);
		cctv(repeat + 1);
		up_re(h[repeat], w[repeat]);

		down(h[repeat], w[repeat]);
		cctv(repeat + 1);
		down_re(h[repeat], w[repeat]);

		left(h[repeat], w[repeat]);
		cctv(repeat + 1);
		left_re(h[repeat], w[repeat]);

		right(h[repeat], w[repeat]);
		cctv(repeat + 1);
		right_re(h[repeat], w[repeat]);
	}
	else if (n[repeat] == 2) {
		up(h[repeat], w[repeat]);
		down(h[repeat], w[repeat]);
		cctv(repeat + 1);
		up_re(h[repeat], w[repeat]);
		down_re(h[repeat], w[repeat]);

		left(h[repeat], w[repeat]);
		right(h[repeat], w[repeat]);
		cctv(repeat + 1);
		left_re(h[repeat], w[repeat]);
		right_re(h[repeat], w[repeat]);
	}
	else if (n[repeat] == 3) {
		up(h[repeat], w[repeat]);
		right(h[repeat], w[repeat]);
		cctv(repeat + 1);
		up_re(h[repeat], w[repeat]);
		right_re(h[repeat], w[repeat]);

		down(h[repeat], w[repeat]);
		left(h[repeat], w[repeat]);
		cctv(repeat + 1);
		down_re(h[repeat], w[repeat]);
		left_re(h[repeat], w[repeat]);

		down(h[repeat], w[repeat]);
		right(h[repeat], w[repeat]);
		cctv(repeat + 1);
		down_re(h[repeat], w[repeat]);
		right_re(h[repeat], w[repeat]);

		up(h[repeat], w[repeat]);
		left(h[repeat], w[repeat]);
		cctv(repeat + 1);
		up_re(h[repeat], w[repeat]);
		left_re(h[repeat], w[repeat]);
	}
	else if (n[repeat] == 4) {
		up(h[repeat], w[repeat]);
		right(h[repeat], w[repeat]);
		left(h[repeat], w[repeat]);
		cctv(repeat + 1);
		up_re(h[repeat], w[repeat]);
		right_re(h[repeat], w[repeat]);
		left_re(h[repeat], w[repeat]);

		up(h[repeat], w[repeat]);
		down(h[repeat], w[repeat]);
		left(h[repeat], w[repeat]);
		cctv(repeat + 1);
		up_re(h[repeat], w[repeat]);
		down_re(h[repeat], w[repeat]);
		left_re(h[repeat], w[repeat]);

		up(h[repeat], w[repeat]);
		down(h[repeat], w[repeat]);
		right(h[repeat], w[repeat]);
		cctv(repeat + 1);
		up_re(h[repeat], w[repeat]);
		down_re(h[repeat], w[repeat]);
		right_re(h[repeat], w[repeat]);

		down(h[repeat], w[repeat]);
		right(h[repeat], w[repeat]);
		left(h[repeat], w[repeat]);
		cctv(repeat + 1);
		down_re(h[repeat], w[repeat]);
		right_re(h[repeat], w[repeat]);
		left_re(h[repeat], w[repeat]);
	}
	else {
		up(h[repeat], w[repeat]);
		down(h[repeat], w[repeat]);
		right(h[repeat], w[repeat]);
		left(h[repeat], w[repeat]);
		cctv(repeat + 1);
		up_re(h[repeat], w[repeat]);
		down_re(h[repeat], w[repeat]);
		right_re(h[repeat], w[repeat]);
		left_re(h[repeat], w[repeat]);
	}

	return 0;
}

int main() {
	scanf("%d %d", &hei, &wid);

	for (int y = 0; y < hei; y++) {
		for (int x = 0; x < wid; x++) {
			scanf("%d", &map[y][x]);
			if ((map[y][x] > 0) && (map[y][x] < 6)) {
				h[num_of_cctv] = y;
				w[num_of_cctv] = x;
				n[num_of_cctv] = map[y][x];
				num_of_cctv++;
				visit[y][x]++;
			}
			else if (map[y][x] == 6) {
				visit[y][x]++;
			}
		}
	}

	cctv(0);

	printf("%d", min);

	return 0;
}
