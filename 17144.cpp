#include <iostream>
using namespace std;

int H, W, T;
int fil_h_1, fil_h_2, fil_w;
int temp, sum = 0;
int map[50][50];
int add[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int air() {
	for (int x = 0; x < W; x++) {
		for (int y = 0; y < H; y++) {
			add[y][x] = 0;
		}
	}
	//add[50][50] = { 0, };
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map[y][x] > 0) {
				if (map[y][x] == 1) add[y][x] += 1;
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
			if (((y == fil_h_1) && (x == fil_w)) || ((y == fil_h_2) && (x == fil_w))) continue;
			map[y][x] = add[y][x];
			add[y][x] = 0;
		}
	}

	return 0;
}

int filter() {
	for (int x = fil_w-2; x > -1; x--) {
		map[fil_h_1][x + 1] = map[fil_h_1][x];
		map[fil_h_2][x + 1] = map[fil_h_2][x];
	} //whole
	for (int y = fil_h_1; y > 0; y--) map[y][0] = map[y - 1][0]; //above
	for (int y = fil_h_2+1; y < H-1; y++) map[y][0] = map[y+1][0]; //bottom
	for (int x = 1; x < W; x++) {
		map[0][x - 1] = map[0][x];
		map[H - 1][x - 1] = map[H - 1][x];
	} //whole
	for (int y = 0; y < fil_h_1; y++) map[y][W - 1] = map[y + 1][W - 1]; //above
	for (int y = H-1; y > fil_h_2; y--) map[y][W - 1] = map[y - 1][W - 1]; //bottom
	for (int x = W - 1; x > fil_w + 1; x--) {
		map[fil_h_1][x] = map[fil_h_1][x - 1];
		map[fil_h_2][x] = map[fil_h_2][x - 1];
	} //above

	map[fil_h_1][fil_w + 1] = 0;
	map[fil_h_2][fil_w + 1] = 0;
	map[fil_h_1][fil_w] = -1;
	map[fil_h_2][fil_w] = -1;

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

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			sum += map[y][x];
		}
	}

	printf("%d", sum+2);

	return 0;
}
