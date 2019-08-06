#include <iostream>
#include <algorithm>
#define len 500001

using namespace std;

int N, M, check, goal[len];
long long number[len], temp, Right, Left, mid;

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%lld", &number[n]);
	}

	sort(number, number + N);

	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		scanf("%lld", &temp);

		check = 0;
		Right = N - 1;
		Left = 0;

		while (Left < Right) {
			if (number[Right] == temp) {
				check = 1;
				break;
			}

			mid = (Left + Right) / 2;

			if (number[mid] == temp) {
				check = 1;
				break;
			}

			if (number[mid] > temp) {
				Right = mid - 1;
				if (Right < mid) {
					Right = mid;
				}
			}
			else {
				Left = mid + 1;
			}
		}

		if (check == 1) goal[m] = 1;
	}

	for (int m = 0; m < M; m++) {
		printf("%d ", goal[m]);
	}

	return 0;
}
