#include<iostream>
#define len 1000001

char A[len], temp;
int N, ans[len], cur;
long long mul = 1;

int main() {
	while (1) {
		scanf("%1c", &temp);

		if (temp == '\n') break;

		A[N] = temp - '0';	N++;
	}

	for (int t = 0; t < N; t++) {
		if (t % 3 == 0) {
			ans[cur] += A[N - 1 - t] * 1;
			cur++;
		}
		else if (t % 3 == 1) {
			ans[cur - 1] += A[N - 1 - t] * 2;
		}
		else {
			ans[cur - 1] += A[N - 1 - t] * 4;
		}
	}

	for (int t = cur - 1; t >= 0; t--) {
		printf("%d", ans[t]);
	}

	return 0;
}
