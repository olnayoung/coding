#include <iostream>

int K, n, d, count;
int score = 0;
int map[4][8];
int number[4], direc[4];


int clock(int x) {
	int temp = map[x][7];

	for (int t = 7; t > 0; t--) {
		map[x][t] = map[x][t-1];
	}

	map[x][0] = temp;

	return 0;
}

int counter_clock(int x) {
	int temp = map[x][0];

	for (int t = 0; t < 7; t++) {
		map[x][t] = map[x][t+1];
	}

	map[x][7] = temp;

	return 0;
}

int rotate() {
	count = 0;
	number[count] = n;
	direc[count] = d;

	if ((n + 1 < 4) && (map[n][2] != map[n + 1][6])) {
		count++;
		number[count] = n+1;
		direc[count] = (d == 1) ? -1 : 1;

		if ((n + 2 < 4) && (map[n+1][2] != map[n + 2][6])) {
			count++;
			number[count] = n+2;
			direc[count] = d;

			if ((n + 3 < 4) && (map[n+2][2] != map[n + 3][6])) {
				count++;
				number[count] = n + 3;
				direc[count] = (d == 1) ? -1 : 1;

			}
		}
	}

	if ((n - 1 > -1) && (map[n][6] != map[n - 1][2])) {
		count++;
		number[count] = n - 1;
		direc[count] = (d == 1) ? -1 : 1;

		if ((n - 2 > -1) && (map[n-1][6] != map[n - 2][2])) {
			count++;
			number[count] = n - 2;
			direc[count] = d;

			if ((n - 3 > -1) && (map[n-2][6] != map[n - 3][2])) {
				count++;
				number[count] = n - 3;
				direc[count] = (d == 1) ? -1 : 1;
			}
		}
	}

	for (int x = 0; x < count+1; x++) {
		if (direc[x] == 1) clock(number[x]);
		else counter_clock(number[x]);
	}
	return 0;
}

int calcul_score() {
	if (map[0][0] == 1) score += 1;
	if (map[1][0] == 1) score += 2;
	if (map[2][0] == 1) score += 4;
	if (map[3][0] == 1) score += 8;

	return 0;
}

int main() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 8; x++) {
			scanf("%1d", &map[y][x]);
		}
	}

	scanf("%d", &K);

	for (int t = 0; t < K; t++) {
		scanf("%d %d", &n, &d);
		n -= 1;

		rotate();
	}
	calcul_score();
	printf("%d", score);

	return 0;
}
