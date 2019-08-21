#include <iostream>
#define len 500001

int N, M, dest, no[10], cur = 100, min;
int T[8];
char D[8];
int ans, total, check;

int makeNumber() {
	int out = 0;
	for (int n = 0; n < N + 1; n++) {
		out = out * 10 + T[n];
	}

	return out;
}

int remote(int n) {
	if (n == N + 1) {
		total = makeNumber();
		ans = (total > dest) ? total - dest : dest - total;
		if (T[0] == 0) ans += N;
		else ans += (N + 1);
		if (T[0] == 0 && T[1] == 1 && T[2] == 1) {
			int a;
			a = 1;
		}
		min = (min < ans) ? min : ans;
		return 0;
	}

	for (int t = 0; t <= 9; t++) {
		check = 0;
		for (int m = 0; m < M; m++) {
			if (t == no[m]) {
				check = 1;	break;
			}
		}

		if (check == 0) {
			T[n] = t;
			remote(n + 1);
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

	T[0] = 0;	remote(1);
	T[0] = 1;	remote(1);

	printf("%d", min);

	return 0;
}
