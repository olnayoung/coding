#include <iostream>
using namespace std;

int N;
int map[20][20];
int team_S[10], team_L[10];
int max = 0;

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

	for (int x = start; x < N; x++) {

	}
	return 0;
}

int main() {
	scanf("%d %d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	print();

	return 0;
}
