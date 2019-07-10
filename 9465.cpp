#include<iostream>

int T, N;
int map[2][100001];
int dp[2][100001];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	scanf("%d", &T);

	for (int test = 0; test < T; test++) {
		scanf("%d", &N);

		dp[0][0] = 0;	dp[1][0] = 0;

		for (int y = 0; y < 2; y++) {
			for (int x = 1; x < N + 1; x++) {
				scanf("%d", &map[y][x]);
			}
		}

		dp[0][1] = map[0][1];	dp[1][1] = map[1][1];

		for (int n = 2; n < N + 1; n++) {
			dp[0][n] = max(dp[1][n - 1], dp[1][n - 2]) + map[0][n];
			dp[1][n] = max(dp[0][n - 1], dp[0][n - 2]) + map[1][n];
		}

		printf("%d\n", max(dp[0][N], dp[1][N]));
	}

	return 0;
}
