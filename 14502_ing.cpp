#include <iostream>
using namespace std;
#define MAX 999999

int H, W;
int map[8][8];
int que_x[MAX];
int que_y[MAX];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int start = 0, finish = 0;
int max = 0;

int walls() {
	for (int a = 0; a < finish - 2; a++) {
		for (int b = a + 1; b < finish - 2; b++) {
			for (int c = b + 1; c < finish - 2; c++) {
				while (start != finish) {
					int temp_x = que_x[start];
					int temp_y = que_y[start];

					for (int t = 0; t < 4; t++) {
						int new_x = temp_x + dx[t];
						int new_y = temp_y + dy[t];

						if ( (new_y < H) && (new_y > -1) && (new_x < W) && (new_x > -1) && (map[new_y][new_x] == 1) ) {

						}
					}
				}

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
				que_x[finish] = x;
				que_y[finish] = y;
				finish++;
			}
		}
	}

	return 0;
}
