#include <iostream>
#include <limits.h>
#define len 1000001

int N;
long long M, tree[len], maxi = LLONG_MAX, mid, mini, sum, remain;

int main() {
	scanf("%d %lld", &N, &M);

	for (int n = 0; n < N; n++) {
		scanf("%lld", &tree[n]);
	}

	while (mini <= maxi) {
		mid = (mini + maxi) / 2;
		sum = 0;

		for (int n = 0; n < N; n++) {
			remain = (tree[n] > mid) ? tree[n] - mid : 0;
			sum += remain;
		}

		if (sum >= M) {
			mini = mid + 1;

			if (mid > maxi) {
				maxi = mid;
			}
		}
		else {
			maxi = mid - 1;
		}
	}

	printf("%lld", maxi);

	return 0;
}
