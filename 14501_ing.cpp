#include <iostream>

int N;
int map[15][2];
int max = 0;
int pos[15];

int calcul_t(int num) {
	int sum = 0;
	for (int x = 0; x < num+1; x++) {
		sum += map[x][0];
	}
	return sum;
}

int calcul_p(int num) {
	int sum = 0;
	for (int x = 0; x < num+1; x++) {
		sum += map[pos[x]][1];
	}
	return sum;
}

int bye(int start, int num) {
	pos[num] = start;
	max = (max > calcul_p(num)) ? max : calcul_p(num);

	for (int x = start; x < N; x++) {
		if (start + map[start][0] > x) continue;
		if (x + map[x][0] < N) {
			pos[num + 1] = x;
			bye(x+1, num+2);
		}
	}

	return 0;
}

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		scanf("%d %d", &map[y][0], &map[y][1]);
	}

	for (int x = 0; x < N; x++) {
		if (x + map[x][0] < N) {
			bye(x, 0);
		}
	}

	printf("%d", max);

	return 0;
}
