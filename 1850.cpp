#include<iostream>

long long A, B, N;

long long g(long long a, long long b) {
	long long c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main() {
	scanf("%lld %lld", &A, &B);

	N = g(A, B);

	for (long long t = 0; t < N; t++) {
		printf("1");
	}

	return 0;
}
