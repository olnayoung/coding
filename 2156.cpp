#include<iostream>

int N, map[10001];
int f[10001];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	scanf("%d", &N);

	if (N == 1) {
		scanf("%d", &map[1]);
		printf("%d", map[1]);

		return 0;
	}

	scanf("%d %d", &map[1], &map[2]);
	f[1] = map[1];	f[2] = map[1] + map[2];

	for (int n = 3; n <= N; n++) {
		scanf("%d", &map[n]);

		f[n] = max(f[n - 3] + map[n - 1] + map[n], f[n - 2] + map[n]);
		f[n] = max(f[n], f[n-1]);
	}

	printf("%d", f[N]);

	return 0;
}
