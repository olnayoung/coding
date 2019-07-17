#include<iostream>

int N;
int map[1001];
long long f[1001];

long long max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	scanf("%d", &N);

	scanf("%d", &map[0]);
	f[0] = map[0];

	for (int n = 1; n < N; n++) {
		scanf("%d", &map[n]);

		f[n] = map[n];
		for (int t = 0; t < n; t++) {
			f[n] = max(f[n], f[n - t - 1] + map[t]);
		}
	}

	printf("%d", f[N - 1]);

	return 0;
}
