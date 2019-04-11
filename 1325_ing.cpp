#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000

int com, line;
int trust[MAX][MAX];
int total[MAX];
int max_count = 0;

int DPS(int start) {
	for (int x = 0; x < com; x++) {
		if (trust[start][x] == 1) {
			total[x] += 1;
			DPS(x);
		}
	}

	return 0;
}

int main() {
	int from, to;
	scanf("%d %d", &com, &line);

	for (int x = 0; x < line; x++) {
		scanf("%d %d", &from, &to);

		trust[from-1][to-1] = 1;
	}

	for (int x = 0; x < com; x++) {
		DPS(x);
	}

	for (int x = 0; x < com; x++) {
		if (total[x] > max_count) {
			max_count = total[x];
		}
	}

	for (int x = 0; x < com; x++) {
		if (total[x] == max_count) {
			printf("%d ", x+1);
		}
	}

	return 0;
}
