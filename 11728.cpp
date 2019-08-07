#include <iostream>
#include <algorithm>
#define len 1000001

using namespace std;

int N, M;
long long A[len], B[len];

int main() {
	scanf("%d %d", &N, &M);

	for (int n = 0; n < N; n++)
		scanf("%lld", &A[n]);

	for (int n = 0; n < M; n++)
		scanf("%lld", &B[n]);

	sort(A, A + N);	sort(B, B + M);

	int n = 0, m = 0;
	for (int t = 0; t < N + M; t++) {
		if ((n < N) && (m < M)) {
			if (A[n] < B[m]) {
				printf("%lld ", A[n]);	n++;
			}
			else {
				printf("%lld ", B[m]);	m++;
			}
		}
		else if ((n < N) && (m >= M)) {
			printf("%lld ", A[n]);	n++;
		}
		else if ((n >= N) && (m < M)) {
			printf("%lld ", B[m]);	m++;
		}
	}

	return 0;
}
