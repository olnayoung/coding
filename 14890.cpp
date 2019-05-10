#include <iostream>
using namespace std;

int N, L;
int map[100][100];
int visit[100][100] = { 0 };
int ways = 0, check;

int clear_v() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			visit[y][x] = 0;
		}
	}

	return 0;
}

int find_way_r() {
	for (int y = 0; y < N; y++) {
		check = 0;

		for (int x = 0; x < N-1; x++) {
			if ( ((map[y][x] - map[y][x+1]) > 1) || ((map[y][x+1] - map[y][x]) > 1) ) {
				check = 1;
				break;
			}
			else if ((map[y][x] - map[y][x + 1]) == 1) {
				for (int t = 0; t < L-1; t++) {
					if ((x + 2 + t > N) || (map[y][x + 1] != map[y][x + 2 + t]) || (visit[y][x + 2 + t] == 1)) {
						check = 1;
						break;
					}
				}

				if (check == 0) {
					for (int t = 0; t < L; t++) visit[y][x + 1 + t] = 1;
				}
			}
			else if ((map[y][x+1] - map[y][x]) == 1) {
				for (int t = 0; t < L; t++) {
					if ((x - t < 0) || (map[y][x] != map[y][x - t]) || (visit[y][x - t] == 1)) {
						check = 1;
						break;
					}
				}

				if (check == 0) {
					for (int t = 0; t < L; t++) visit[y][x - t] = 1;
				}
			}

			if (check == 1) break;
		}

		if (check == 0) ways++;
	}
	return 0;
}

int find_way_c() {
	for (int x = 0; x < N; x++) {
		check = 0;

		for (int y = 0; y < N - 1; y++) {
			if (((map[y+1][x] - map[y][x]) > 1) && ((map[y+1][x] - map[y][x]) > 1)) {
				check = 1;
				break;
			}
			else if ((map[y][x] - map[y+1][x]) == 1) {
				for (int t = 0; t < L - 1; t++) {
					if ((y + 2 + t > N) || (map[y + 1][x] != map[y + 2 + t][x]) || (visit[y + 2 + t][x] == 1)) {
						check = 1;
						break;
					}
				}

				if (check == 0) {
					for (int t = 0; t < L; t++) visit[y + 1 + t][x] = 1;
				}
			}
			else if ((map[y + 1][x] - map[y][x]) == 1) {
				for (int t = 0; t < L; t++) {
					if ((y - t < 0) || (map[y][x] != map[y - t][x]) || (visit[y - t][x] == 1)) {
						check = 1;
						break;
					}
				}

				if (check == 0) {
					for (int t = 0; t < L; t++) visit[y - t][x] = 1;
				}
			}

			if (check == 1) break;
		}

		if (check == 0) ways++;
	}
	return 0;
}

int main() {
	scanf("%d %d", &N, &L);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	find_way_r();
	clear_v();
	find_way_c();

	printf("%d", ways);

	return 0;
}
