#include<iostream>

int K;
int map[1000002];

int min(int a, int b) {
	return (a < b) ? a : b;
}

int main() {
	scanf("%d", &K);
	map[1] = 0;
	map[2] = 1;
	map[3] = 1;

	for (int n = 4; n < K + 1; n++) {
		if (n % 3 == 0) {
			map[n] = min(map[n/3] + 1, map[n-1] + 1);
		}
		else if (n % 2 == 0) {
			map[n] = min(map[n/2] + 1, map[n-1] + 1);
		}
		else {
			map[n] = map[n - 1] + 1;
		}
	}

	printf("%d", map[K]);

	return 0;
}
