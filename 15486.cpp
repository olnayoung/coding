#include <iostream>
#define len 1500002
#define MAX(a, b) (a > b) ? a : b

int N, T[len], P[len];
long long dp[len];

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		scanf("%d %d", &T[n], &P[n]);
	}

	for (int n = N; n > 0; n--) {
		if (n + T[n] > N + 1) {
			dp[n] = dp[n+1];
		}
		else {
			dp[n] = MAX(dp[n+1], P[n] + dp[n + T[n]]);
		}
	}

	printf("%lld", dp[1]);

	return 0;
}
