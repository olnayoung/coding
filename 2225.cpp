#include<iostream>

int N, K;
long long f[201][201];

int main() {
	scanf("%d %d", &N, &K);

	for (int n = 1; n <= N; n++) {
		f[n][1] = 1;
	}

	for (int k = 1; k <= K; k++) {
		f[1][k] = k;
	}

	for (int n = 2; n <= N; n++) {
		for (int k = 2; k <= K; k++) {
			f[n][k] = (f[n - 1][k] + f[n][k - 1]) % 1000000000;
		}
	}

	printf("%lld", f[N][K]);

	return 0;
}
