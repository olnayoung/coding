#include<iostream>

int N, f[100001];

int min(int a, int b) {
	return (a < b) ? a : b;
}

int main() {
	scanf("%d", &N);

	f[1] = 1;	f[2] = 2;	f[3] = 3;	f[4] = 1;
	for (int n = 5; n <= N; n++) {
		f[n] = n;
		for (int t = 2; t*t <= n; t++) {
			f[n] = min(f[n], f[n - t*t] + 1);
		}
	}

	printf("%d", f[N]);

	return 0;
}
