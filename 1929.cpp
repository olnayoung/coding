#include<iostream>
#define len 1000001

int A, B;
int prime[len];

int find_prime() {
	prime[1] = 1;
	for (int y = 2; y <= B; y++) {
		if (prime[y] == 0){
			for (int x = 2 * y; x <= B; x += y) {
				prime[x] = 1;
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d %d", &A, &B);

	find_prime();

	for (int t = A; t <= B; t++) {
		if (prime[t] == 0)	printf("%d\n", t);
	}

	return 0;
}
