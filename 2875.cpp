#include <iostream>

int N, M, K, team, remain;

int student() {
	if (N / 2 > M) {
		team = M;
		remain = N - team * 2;
	}
	else {
		team = N / 2;
		remain = M - team;
	}

	if (remain < K) {
		K -= remain;
		if (K % 3 == 0) {
			team = team - (K / 3);
		}
		else {
			team = team - (K / 3) - 1;
		}
	}

	return 0;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	student();

	printf("%d", team);

	return 0;
}
