#include<iostream>

int T, N;
long long f[101];

int main() {
	scanf("%d", &T);

	f[1] = 1;	f[2] = 1;	f[3] = 1;	f[4] = 2;	f[5] = 2;

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		for (int n = 6; n <= N; n++) {
			f[n] = f[n - 1] + f[n - 5];
		}

		printf("%lld\n", f[N]);
	}

	return 0;
}
