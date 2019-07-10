#include<iostream>

int N;
long long f[9][100], sum;

int main() {
	scanf("%d", &N);
	
	for (int t = 0; t < 9; t++) {
		f[t][0] = 1;	f[t][1] = 2;
	}
	f[8][1] = 1;

	for (int n = 2; n < N; n++) {
		f[0][n] = (f[0][n - 2] + f[1][n - 1]) % 1000000000;
		for (int t = 1; t < 8; t++) {
			f[t][n] = (f[t - 1][n - 1] + f[t + 1][n - 1]) % 1000000000;
		}
		f[8][n] = f[7][n - 1];
	}

	for (int t = 0; t < 9; t++) {
		sum = (sum + f[t][N - 1]) % 1000000000;
	}

	printf("%d", sum);

	return 0;
}
