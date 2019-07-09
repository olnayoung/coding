#include<iostream>

int N;
long long map[1001], ans;

int main() {
	scanf("%d", &N);
	map[0] = 1;
	map[1] = 3;

	for (int t = 2; t < N; t++) {
		map[t] = (map[t - 1] + map[t - 2] * 2) % 10007;
	}


	printf("%lld", map[N-1]);

	return 0;
}
