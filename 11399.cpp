#include <iostream>
#define len 1001

int N, P[len], Q[len];
long long ans;

int merge(int left, int mid, int right) {
	int i, j, k;
	i = left, j = mid + 1; k = left;

	while ((i <= mid) && (j <= right)) {
		if (P[i] <= P[j]) {
			Q[k++] = P[i++];
		}
		else {
			Q[k++] = P[j++];
		}
	}

	if (i > mid) {
		for (int t = j; t <= right; t++) {
			Q[k++] = P[t];
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			Q[k++] = P[t];
		}
	}

	for (int t = left; t <= right; t++) {
		P[t] = Q[t];
	}

	return 0;
}

int MergeSort(int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		merge(left, mid, right);
	}

	return 0;
}

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		scanf("%d", &P[n]);
	}

	MergeSort(0, N - 1);

	for (int n = 0; n < N; n++) {
		ans += (P[n] * (N-n));
	}

	printf("%lld", ans);

	return 0;
}  
