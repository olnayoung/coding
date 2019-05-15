#include <iostream>
#define MAX 999999

int N, i, j, d, g;
int cen_x, cen_y;
int map[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int h[MAX], w[MAX];
int num, count = 0;

int clear() {
	for (int x = 0; x < 100; x++) {
		for (int y = 0; y < 100; y++) {
			map[y][x] = 0;
		}
	}
	return 0;
}

int count_number() {
	for (int x = 0; x < 104; x++) {
		for (int y = 0; y < 104; y++) {
			if (map[y][x] == 1)	{
				if ((map[y+1][x] == 1) && (map[y][x+1] == 1) && (map[y+1][x+1]))	count++;
			}
		}
	}
	return 0;
}

int rotate_x(int x, int y) {
	return cen_y - y + cen_x;
	//return y - cen_y + cen_x;
}

int rotate_y(int x, int y) {
	return x - cen_x + cen_y;
	//return cen_x - x + cen_y;
}

int curve(int gen) { // gen -> gen+1
	num = 2;

	for (int x = 0; x < gen; x++) {
		num = num * 2 - 1;
	}

	int t;

	for (t = 0; t < num-1; t++) {
		h[t + num] = rotate_y(w[num - t - 2], h[num - t - 2]);
		w[t + num] = rotate_x(w[num - t - 2], h[num - t - 2]);
	}

	cen_y = h[t + num - 1];
	cen_x = w[t + num - 1];

	return 0;
}

int main() {
	scanf("%d", &N);
	clear();

	for (int t = 0; t < N; t++) {
		scanf("%d %d %d %d", &i, &j, &d, &g);
		cen_y = j + dy[d];
		cen_x = i + dx[d];

		h[0] = j;	h[1] = cen_y;
		w[0] = i;	w[1] = cen_x;

		map[h[0]][w[0]] = 1;
		map[h[1]][w[1]] = 1;

		for (int x = 0; x < g; x++) {
			curve(x);
		}

		for (int x = 0; x < num*2 + 1; x++) {
			if ((h[x] > -1) && (h[x] < 105) && (w[x] > -1) && (w[x] < 105))
			map[h[x]][w[x]] = 1;
		}

		
	}

	count_number();

	printf("%d", count);

	return 0;
}
