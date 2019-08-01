#include <iostream>
#include <limits.h>
#define len 10001

int N, K, num;
long long have[len], maxi = LLONG_MAX, mid, mini;

int main() {
	scanf("%d %d", &K, &N);

	for (int k = 0; k < K; k++) {
		scanf("%lld", &have[k]);
	}

	while (mini <= maxi) {
		mid = (mini + maxi) / 2;
		num = 0;

		for (int k = 0; k < K; k++) {
			num += (have[k] / mid);
		}

		if (num >= N) {
			mini = mid + 1;
			if (mid > maxi) {
				maxi = mid;
			}
		}
		else
			maxi = mid - 1;
	}

	printf("%lld", maxi);

	return 0;
}
