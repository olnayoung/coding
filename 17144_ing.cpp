#include <iostream>
using namespace std;

int H, W, T;
int fil_h_1, fil_h_2, fil_w;
int temp;
int map[50][50];
int add[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int air() {
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] > 0) {
				if (map[y][x] == 1) {
					add[y][x] += 1;
				}
				else {
					temp = map[y][x] / 5;
					int count = 0;

					for (int a = 0; a < 4; a++) {
						int new_y = dy[a] + y;
						int new_x = dx[a] + x;

						if ((new_y < H) && (new_y > -1) && (new_x < W) && (new_x > -1) && (map[new_y][new_x] != -1)) {
							add[new_y][new_x] += temp;
							count += 1;
						}
					}

					add[y][x] += (map[y][x] - (temp * count));
				}
			}
		}
	}

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if ( ((y == fil_h_1) && (x == fil_w)) || ((y == fil_h_2) && (x == fil_w)) ) continue;
			map[y][x] = add[y][x];
			add[y][x] = 0;
		}
	}

	return 0;
}

int filter() {

	return 0;
}

int main() {

	scanf("%d %d %d", &H, &W, &T);

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			scanf("%d", &map[y][x]);

			if (map[y][x] == -1) {
				fil_h_2 = y;
				fil_w = x;
			}
		}
	}
	fil_h_1 = fil_h_2 - 1;

	for (int t = 0; t < T; t++) {
		air();
		filter();
	}

	printf("\n");
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}

	return 0;
}
