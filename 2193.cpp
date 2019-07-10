#include<iostream>

int N;
long long f[2][90];

int main() {
	scanf("%d", &N);
	
	f[0][0] = 1;	f[1][0] = 1;

	for (int n = 1; n < N; n++) {
		f[0][n] = f[0][n - 1] + f[1][n - 1];
		f[1][n] = f[0][n - 1];
	}

	printf("%lld", f[1][N - 1]);

	return 0;
}
