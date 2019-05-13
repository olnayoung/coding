#include <iostream>
using namespace std;

int N;
int map[20][20];
int team_S[10], team_L[10];
int min = 9999999;

int calcul_max() {
	int sum1 = 0, sum2 = 0;
	int M = N / 2;

	for (int x = 0; x < M; x++) {
		for (int y = 0; y < M; y++) {
			if (x == y) continue;

			sum1 += map[team_S[x]][team_S[y]];
			sum2 += map[team_L[x]][team_L[y]];
		}
	}

	int temp = (sum1 > sum2) ? sum1 - sum2 : sum2 - sum1;
	return temp;
}

int find_max(int start, int num) {
	int M = N / 2;

	for (int x = start; x < N - M + num + 1; x++) {
		team_S[num] = x;

		if ((num + 1) == M) {
			int k = 0;
			for (int x = 0; x < N; x++) {
				int check = 0;

				for (int y = 0; y < M; y++) {
					if (x == team_S[y]) {
						check = 1;
						break;
					}
				}

				if (check == 0) {
					team_L[k] = x;
					k++;
				}
			}

			min = (min > calcul_max()) ? calcul_max() : min;
		}

		if (num < M-1) {
			find_max(x + 1, num + 1);
		}
	}
	return 0;
}

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	find_max(0, 0);
	printf("%d", min);

	return 0;
}
