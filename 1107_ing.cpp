#include <iostream>
#define len 500001

int N, M, dest, no[10], cur = 100, min;
int T[8];
char D[8];
int ans, total;

int makeNumber() {
	int out = 0;
	for (int n = 0; n < N; n++) {
		out = out * 10 + T[n];
	}

	return out;
}

int remote() {
	int check, check2 = 1, small = D[0] - 1, big = D[0] + 1, small_dist, big_dist, temp;

	for (int n = 0; n < N; n++) {
		check = 0;
		for (int m = 0; m < M; m++) {
			if (D[n] == no[m]) {
				check = 1;	break;
			}
		}

		if ((check == 0) && (check2 == 1)) {
			T[n] = D[n];
			check2 = 1;
			continue;
		}
		else {
			check2 = 0;
			for (int m = M - 1; m > -1; m--) {
				if (small == no[m]) small--;
				if (small > no[m]) break;
			}

			for (int m = 0; m < M; m++) {
				if (big == no[m]) big++;
				if (big < no[m]) break;
			}

			if (small < 0)	small_dist = len;
			else {
				T[n] = small;
				temp = makeNumber();
				small_dist = (temp > dest) ? temp - dest : dest - temp;
			}

			if (big > 9)	big_dist = len;
			else {
				T[n] = big;
				temp = makeNumber();
				big_dist = (temp > dest) ? temp - dest : dest - temp;
			}

			if (small_dist > big_dist) {
				T[n] = big;
				small = 0;
			}
			else {
				T[n] = small;
				big = 9;
			}
		}
	}

	return 0;
}

int main() {
	char get_temp;
	while (1) {
		scanf("%1c", &get_temp);
		if (get_temp < '0' || get_temp > '9') break;
		D[N] = get_temp - '0';
		N++;
	}

	for (int n = 0; n < N; n++) {
		dest = dest * 10 + D[n];
	}

	min = (dest > cur) ? dest - cur : cur - dest;

	scanf("%d", &M);
	for (int m = 0; m < M; m++)
		scanf("%d", &no[m]);

	remote();

	total = makeNumber();
	ans = (total > dest) ? total - dest : dest - total;
	ans += N;

	T[0] = 1;
	for (int n = 1; n < N + 1; n++) {
		T[n] = 0;
	}

	for (int n = 0; n < N + 1; n++) {
		for (int m = 0; m < M; m++) {
			if (T[n] == no[m]) T[n]++;
			if (T[n] < no[m]) break;
		}
	}

	total = makeNumber() * 10;

	ans = (total - dest + N + 1 > ans) ? ans : total - dest + N + 1;
	ans = (ans < min) ? ans : min;

	printf("%d", ans);

	return 0;
}
