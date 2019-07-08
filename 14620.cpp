#include<iostream>

int N, min = 9999, temp;
int map[10][10];
int dif_y, dif_x;
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int plant() {
	for (int y = 1; y < N - 1; y++) {
		for (int x = 1; x < N - 1; x++) {

			for (int yy = 1; yy < N - 1; yy++) {
				for (int xx = 1; xx < N - 1; xx++) {
					dif_y = (yy > y) ? yy - y : y - yy;
					dif_x = (xx > x) ? xx - x : x - xx;

					if (dif_y + dif_x > 2) {
						for (int yyy = 1; yyy < N - 1; yyy++) {
							for (int xxx = 1; xxx < N - 1; xxx++) {
								dif_y = (yyy > y) ? yyy - y : y - yyy;
								dif_x = (xxx > x) ? xxx - x : x - xxx;

								if (dif_y + dif_x > 2) {
									dif_y = (yyy > yy) ? yyy - yy : yy - yyy;
									dif_x = (xxx > xx) ? xxx - xx : xx - xxx;

									if (dif_y + dif_x > 2) {
										temp = 0;
										for (int t = 0; t < 5; t++) {
											temp = temp + map[y + dy[t]][x + dx[t]] + map[yy + dy[t]][xx + dx[t]] + map[yyy + dy[t]][xxx + dx[t]];
										}
										min = (min < temp) ? min : temp;
									}
								}
							}
						}
					}

				}
			}

		}
	}

	return 0;
}

int main(){
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	plant();

	printf("%d", min);

	return 0;
}
