#include<iostream>

int N;
int f[10][1000], sum;

int main() {
	scanf("%d", &N);
	
	for (int t = 0; t < 10; t++) {
		f[t][0] = 1;
	}

	for (int n = 1; n < N; n++) {
		f[9][n] = 1;
		for (int t = 8; t > -1; t--) {
			f[t][n] = (f[t][n - 1] + f[t + 1][n]) % 10007;
		}
	}

	for (int t = 0; t < 10; t++) {
		sum = (sum + f[t][N - 1]) % 10007;
	}

	printf("%d", sum);

	return 0;
}
