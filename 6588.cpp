#include<iostream>
#define len 1000001

int A, n, m, check;
int prime[len];

int find_prime() {
	prime[1] = 1;
	for (int y = 2; y <= A; y++) {
		if (prime[y] == 0){
			for (int x = 2 * y; x <= A; x += y) {
				prime[x] = 1;
			}
		}
	}

	return 0;
}

int main() {
	A = len - 1;
	find_prime();

	while (1) {
		scanf("%d", &A);
		if (A == 0)	break;

		n = 2;
		check = 0;

		while (n <= A / 2) {
			m = A - n;
			if ((prime[n] == 0) && (prime[m] == 0)) {
				printf("%d = %d + %d\n", A, n, m);
				check = 1;
				break;
			}
			n++;
		}

		if (check == 0) {
			printf("Goldbach's conjecture is wrong.\n");
		}
	}

	return 0;
}
