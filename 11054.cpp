#include<iostream>

int N, map[1000];
int f[1000], f_back[1000], max, max_back, ans_max;

int main() {
	scanf("%d", &N);

	scanf("%d", &map[0]);
	f[0] = 1;
	f_back[N - 1] = 1;
	ans_max = 2;

	for (int n = 1; n < N; n++) {
		scanf("%d", &map[n]);
	}

	for (int n = 1; n < N; n++) {
		max = 0;
		max_back = 0;
		for (int t = 0; t < n; t++) {
			if (map[t] < map[n]) {
				max = (max > f[t]) ? max : f[t];
			}
			if (map[N - 1 - t] < map[N - 1 - n]) {
				max_back = (max_back > f_back[N - 1 - t]) ? max_back : f_back[N - 1 - t];
			}
		}
		f[n] = max + 1;
		f_back[N - 1 - n] = max_back + 1;
	}

	for (int n = 0; n < N; n++) {
		ans_max = (ans_max > f[n] + f_back[n]) ? ans_max : f[n] + f_back[n];
	}

	printf("%d", ans_max - 1);

	return 0;
}
