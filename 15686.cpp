#include <iostream>

int N, M;
int map[50][50];
int house, h_house[100], w_house[100];
int chick, h_chick[13], w_chick[13], chosen[13];
int each_length[100][13];
int min = 9999999, sum, min_length;

int calcul() {
	for (int t = 0; t < house; t++) {
		for (int tt = 0; tt < chick; tt++) {
			int y = h_house[t] - h_chick[tt];
			int x = w_house[t] - w_chick[tt];

			y = (y > 0) ? y : -y;
			x = (x > 0) ? x : -x;
			each_length[t][tt] = y + x;
		}
	}
	return 0;
}

int find_chick() {
	sum = 0;
	for (int t = 0; t < house; t++) {
		min_length = 9999;
		for (int tt = 0; tt < M; tt++) {
			min_length = (min_length < each_length[t][chosen[tt]]) ? min_length : each_length[t][chosen[tt]];
		}
		sum += min_length;
	}

	min = (min < sum) ? min : sum;

	return 0;
}

int left_ones(int start, int num) {
	if (num == M) {
		find_chick();
		return 0;
	}

	for (int x = start; x < chick - M + num + 1; x++) {
		chosen[num] = x;

		left_ones(x + 1, num + 1);
	}

	return 0;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 1) {
				h_house[house] = y;
				w_house[house] = x;
				house++;
			}

			if (map[y][x] == 2) {
				h_chick[chick] = y;
				w_chick[chick] = x;
				chick++;
			}

		}
	}

	calcul();

	left_ones(0, 0);

	printf("%d", min);

	return 0;
}
