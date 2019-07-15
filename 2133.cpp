#include<iostream>

int N;
long long f[31];

int main() {
	scanf("%d", &N);

	f[0] = 1;	f[2] = 3;
	for (int n = 4; n <= N; n++) {
		if (n % 2 != 0)	continue;

		f[n] = f[n - 2] * 3;
		for (int t = 4; t <= n; t+=2) {
			f[n] = f[n] + f[n - t] * 2;
		}
	}

	printf("%lld", f[N]);

	return 0;
}
