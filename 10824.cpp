#include<iostream>

long long A, B, C, D, temp = 1;
long long ans1, ans2;


int main() {
	scanf("%d %d %d %d", &A, &B, &C, &D);

	for (int t = 0; t < 6; t++) {
		if (B / temp == 0) break;
		temp *= 10;
	}
	ans1 = A * temp + B;

	temp = 1;
	for (int t = 0; t < 6; t++) {
		if (D / temp == 0) break;
		temp *= 10;
	}
	ans2 = C * temp + D;

	printf("%lld", ans1 + ans2);

	return 0;
}
