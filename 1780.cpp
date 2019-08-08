#include <iostream>
#include <algorithm>
#define len 3*3*3*3*3*3*3
using namespace std;

int N, paper[len][len], temp, total[3];

int small(int s_y, int s_x, int s) {
	temp = paper[s_y][s_x];
	for (int y = s_y; y < s_y + s; y++) {
		for (int x = s_x; x < s_x + s; x++) {
			if (paper[y][x] != temp)	return 1;
		}
	}

	if (temp == -1)	total[0]++;
	else if (temp == 0)	total[1]++;
	else total[2]++;

	return 0;
}

int split(int s_y, int s_x, int s) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (small(s_y + s*y, s_x + s*x, s)) {
				split(s_y + s*y, s_x + s*x, s / 3);
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &paper[y][x]);
		}
	}

	if (small(0, 0, N)) {
		split(0, 0, N / 3);
	}

	for (int t = 0; t < 3; t++)
		printf("%d\n", total[t]);

	return 0;
}
