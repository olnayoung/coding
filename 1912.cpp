#include<iostream>

int N, map[100000], num;
long long sum[100000], max[100000], ans = -1000;

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		scanf("%d", &map[n]);
		max[n] = map[n];

		if (map[n] > 0) {
			num++;
		}

		for (int t = 0; t < num; t++) {
			sum[t] = sum[t] + map[n];
			if (map[n] > 0) {
				max[t] = (max[t] > sum[t]) ? max[t] : sum[t];
			}
		}
	}

	for (int n = 0; n < N; n++) {
		ans = (ans > max[n]) ? ans : max[n];
	}

	printf("%lld", ans);

	return 0;
}
