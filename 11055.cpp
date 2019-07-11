#include<iostream>

int N, map[1000];
long long f[1000], max, ans_max;

int main() {
	scanf("%d", &N);

	scanf("%d", &map[0]);
	f[0] = map[0];
	ans_max = f[0];

	for (int n = 1; n < N; n++) {
		scanf("%d", &map[n]);

		max = 0;
		for (int t = 0; t < n; t++) {
			if (map[t] < map[n]) {
				max = (max > f[t]) ? max : f[t];
			}
		}
		f[n] = max + map[n];
		ans_max = (ans_max > f[n]) ? ans_max : f[n];
	}

	printf("%lld", ans_max);

	return 0;
}
