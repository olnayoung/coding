#include <iostream>
using namespace std;

int N, L;
int map[100][100];
int visit[100][100] = { 0 };
int ways = 0, check;

int print_v() {
	printf("\n");
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%d ", visit[y][x]);
		}
		printf("\n");
	}

	return 0;
}

int print() {
	printf("\n");
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}

	return 0;
}

int find_way_r() {
	for (int y = 0; y < N; y++) {
		check = 0;

		for (int x = 0; x < N-1; x++) {
			if ( ((map[y][x] - map[y][x+1]) > 1) && ((map[y][x+1] - map[y][x]) < -1) ) {
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

int main() {
	scanf("%d %d", &N, &L);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	find_way_r();
	print();

	printf("%d", ways);

	return 0;
}
