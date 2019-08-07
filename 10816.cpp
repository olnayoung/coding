#include <iostream>
#include <algorithm>
#define len 500001
#define maximum 10000000

using namespace std;

int N, M, goal[len];
long long number[len], temp, Right, Left, mid, save_mid, many[maximum*2+1];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%lld", &number[n]);
		many[number[n] + maximum]++;
	}

	sort(number, number + N);

	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		scanf("%lld", &temp);

		Right = N - 1;
		Left = 0;

		while (Left < Right) {
			if (number[Right] == temp) {
				goal[m] += many[number[Right] + maximum];
				break;
			}

			mid = (Left + Right) / 2;

			if (number[mid] == temp) {
				goal[m] += many[number[mid] + maximum];
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
	}

	for (int m = 0; m < M; m++) {
		printf("%d ", goal[m]);
	}

	return 0;
}
