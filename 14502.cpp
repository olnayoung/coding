#include <iostream>
using namespace std;
#define MAX 999999

int H, W;
int map[8][8];
int map_copy[8][8];
int visit_0[8][8];
int que_x_2[MAX], que_y_2[MAX];
int que_x_0[64], que_y_0[64];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int start = 0, finish = 0, finish_0 = 0;
int max_num = 0, num;

int copy() {
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			map_copy[y][x] = map[y][x];
			visit_0[y][x] = 0;
		}
	}

	return 0;
}

int count() {
	num = 0;

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (map_copy[y][x] == 0) {
				num++;
			}
		}
	}

	return num;
}

int walls() {
	for (int a = 0; a < finish_0 - 2; a++) {
		for (int b = a + 1; b < finish_0 - 1; b++) {
			for (int c = b + 1; c < finish_0; c++) {
				copy();
				map_copy[que_y_0[a]][que_x_0[a]] = 1;
				map_copy[que_y_0[b]][que_x_0[b]] = 1;
				map_copy[que_y_0[c]][que_x_0[c]] = 1;
				
				int temp_start = start;
				int temp_finish = finish;
				while (temp_start != temp_finish) {
					int temp_x = que_x_2[temp_start];
					int temp_y = que_y_2[temp_start];

					for (int t = 0; t < 4; t++) {
						int new_x = temp_x + dx[t];
						int new_y = temp_y + dy[t];

						if ( (new_y < H) && (new_y > -1) && (new_x < W) && (new_x > -1) && (map_copy[new_y][new_x] == 0) && (visit_0[new_y][new_x] == 0) ) {
							map_copy[new_y][new_x] = 2;
							que_x_2[temp_finish] = new_x;
							que_y_2[temp_finish] = new_y;
							visit_0[new_y][new_x] = 1;
							temp_finish++;
						}
					}

					temp_start++;
				} //while

				num = count();
				max_num = (max_num > num) ? max_num : num;
			}
		}
	}
	return 0;
}

int main() {

	scanf("%d %d", &H, &W);

	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			scanf("%d", &map[y][x]);

			if (map[y][x] == 2) {
				que_x_2[finish] = x;
				que_y_2[finish] = y;
				finish++;
			}
			else if (map[y][x] == 0) {
				que_x_0[finish_0] = x;
				que_y_0[finish_0] = y;
				finish_0++;
			}
		}
	}

	walls();

	printf("%d", max_num);

	return 0;
}
