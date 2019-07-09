#include<iostream>

int N;
int map[301];
long long ans[301];

int max(int a, int b) {
	int c = (a > b) ? a : b;

	return c;
}

int main() {
	scanf("%d", &N);
	scanf("%d %d %d", &map[0], &map[1], &map[2]);
	ans[0] = map[0];
	ans[1] = map[0] + map[1];
	ans[2] = map[2] + max(map[0], map[1]);

	for (int t = 3; t < N; t++) {
		scanf("%d", &map[t]);
		ans[t] = map[t] + max(map[t-1] + ans[t-3], ans[t-2]);
	}

	printf("%lld", ans[N-1]);

	return 0;
}
