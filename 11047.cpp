#include <iostream>

int N, money[10];
long long K, ans;

int calcul() {
	long long remain = K;
	int number;

	for (int n = N - 1; n > -1; n--) {
		if (remain >= money[n]) {
			number = remain / money[n];
			remain -= (money[n] * number);
			ans += number;
		}
	}

	return 0;
}

int main() {
	scanf("%d %lld", &N, &K);

	for (int n = 0; n < N; n++)
		scanf("%d", &money[n]);

	calcul();
	printf("%lld", ans);

	return 0;
}
