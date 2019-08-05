#include <iostream>
#include <algorithm>
#define len 1000001

using namespace std;

int N, C;
long long house[len], maxi, mid, mini, num, previous, ans;

int main() {
	scanf("%d %d", &N, &C);

	for (int n = 0; n < N; n++) {
		scanf("%lld", &house[n]);
	}

	sort(house, house + N);
	maxi = house[N - 1] - house[0];
	mini = 1;

	while (maxi >= mini) {
		mid = (maxi + mini) / 2;
		num = 1;
		previous = house[0];

		for (int n = 1; n < N; n++) {
			if ((house[n] - previous) >= mid) {
				num++;
				previous = house[n];
			}
		}

		if (num >= C) {
			mini = mid + 1;
			ans = (ans > mid) ? ans : mid;
		}
		else {
			maxi = mid - 1;
		}
	}

	printf("%lld", ans);

	return 0;
}
