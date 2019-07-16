#include<iostream>
#define div 1000000

char num[5003];
int N = 1, temp;
int f[5003];

int main() {
	while (1) {
		scanf("%1c", &num[N]);
		if ((num[N] < 48) || (num[N] > 57))	break;
		num[N] -= '0';
		N++;
	}

	if ((num[0] == 0) && (N == 1)) {
		printf("0");	return 0;
	}

	f[0] = 1;

	for (int n = 1; n <= N; n++) {
		if (num[n] != 0) {
			f[n] = (f[n] + f[n - 1]) % div;
		}

		if (n == 1)	continue;
		temp = num[n] + 10 * num[n - 1];

		if ((temp > 9) && (temp < 27)) {
			f[n] = (f[n] + f[n - 2]) % div;
		}
	}

	printf("%d", f[N-1]);

	return 0;
}
