#include <cstdio>

int N, max = 0;
int map[20][20], ori_map[20][20];
int order[5];

int clear() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x] = ori_map[y][x];
		}
	}
	return 0;
}

int calcul()  {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			max = (max > map[y][x]) ? max : map[y][x];
		}
	}
	return 0;
}

int get_max() {
	
	for (int t = 0; t < 5; t++) {
		if (order[t] == 0) {
			for (int y = 0; y < N; y++) { // ->
				for (int x = N-1; x > 0; x--) {
					if (map[y][x] == 0)	continue;
					if ((map[y][x] != map[y][x - 1]) && (map[y][x - 1] != 0))	continue;

					for (int i = 1; i < x + 1; i++) { // add
						if ((map[y][x - i] != 0) && (map[y][x - i] != map[y][x])) break;
						if (map[y][x] == map[y][x - i]) {
								map[y][x] += map[y][x - i];
								map[y][x - i] = 0;
								break;
						}
					}
					
				}
			}

			for (int y = 0; y < N; y++) { // move
				for (int x = 1; x < N; x++) {
					for (int aaa = 0; aaa < 20; aaa++) {
						if (map[y][x] != 0)	break;
						else {
							for (int t = x; t > 0; t--) {
								map[y][t] = map[y][t - 1];
							}
							map[y][0] = 0;
						}
					}
				}
			}

		}

		if (order[t] == 1) { // down
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < N - 1; y++) {
					if (map[y][x] == 0)	continue;
					if ((map[y][x] != map[y + 1][x]) && (map[y + 1][x] != 0))	continue;

					for (int i = 1; i < N - y; i++) { // add
						if ((map[y + i][x] != 0) && (map[y + i][x] != map[y][x])) break;
						if (map[y][x] == map[y + i][x]) {
								map[y][x] += map[y + i][x];
								map[y + i][x] = 0;
								break;
						}
					}

				}
			}

			for (int x = 0; x < N; x++) { // move
				for (int y = 0; y < N - 1; y++) {
					for (int aaa = 0; aaa < 20; aaa++) {
						if (map[y][x] != 0)	break;
						else {
							for (int t = y; t < N; t++) {
								map[t][x] = map[t + 1][x];
							}
							map[N - 1][x] = 0;
						}
					}
				}
			}

		}

		if (order[t] == 2) {
			for (int y = 0; y < N; y++) { // <-
				for (int x = 0; x < N - 1; x++) {
					if (map[y][x] == 0)	continue;
					if ((map[y][x] != map[y][x + 1]) && (map[y][x + 1] != 0))	continue;

					for (int i = 1; i < N - x; i++) { // add
						if ((map[y][x + i] != 0) && (map[y][x + i] != map[y][x])) break;
						if (map[y][x] == map[y][x + i]) {
							map[y][x] += map[y][x + i];
							map[y][x + i] = 0;
							break;
						}
					}

				}
			}

			for (int y = 0; y < N; y++) { // move
				for (int x = 0; x < N - 1; x++) {
					for (int aaa = 0; aaa < 20; aaa++) {
						if (map[y][x] != 0)	break;
						else {
							for (int t = x; t < N; t++) {
								map[y][t] = map[y][t + 1];
							}
							map[y][N - 1] = 0;
						}
					}
				}
			}

		}

		if (order[t] == 3) {
			for (int x = 0; x < N; x++) { // up
				for (int y = N-1; y > 0; y--) {
					if (map[y][x] == 0)	continue;
					if ((map[y][x] != map[y - 1][x]) && (map[y - 1][x] != 0))	continue;

					for (int i = 1; i < y + 1; i++) { // add
						if ((map[y - i][x] != 0) && (map[y - i][x] != map[y][x])) break;
						if (map[y][x] == map[y - i][x]) {
							map[y][x] += map[y - i][x];
							map[y - i][x] = 0;
							break;
						}
					}

				}
			}

			for (int x = 0; x < N; x++) { // move
				for (int y = 1; y < N; y++) {
					for (int aaa = 0; aaa < 20; aaa++) {
						if (map[y][x] != 0)	break;
						else {
							for (int t = y; t > 0; t--) {
								map[t][x] = map[t - 1][x];
							}
							map[0][x] = 0;
						}
					}
				}
			}

		}
	}
	return 0;
}

int make_order(int num) {
	if (num == 5) {
		clear();
		get_max();
		calcul();
		return 0;
	}

	for (int t = 0; t < 4; t++) {
		order[num] = t;
		make_order(num + 1);
	}

	return 0;
}

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
			ori_map[y][x] = map[y][x];
		}
	}
	make_order(0);

	printf("%d", max);

	return 0;
}
