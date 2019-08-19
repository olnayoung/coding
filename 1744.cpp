#include <iostream>
#define len 10001

int N, sr[len], sr2[len];
long long ans;

int merge(int left, int mid, int right) {
	int i, j, k;
	i = left; j = mid + 1; k = left;

	while ((i <= mid) && (j <= right)) {
		if (sr[i] >= sr[j]) {
			sr2[k++] = sr[j++];
		}
		else {
			sr2[k++] = sr[i++];
		}
	}

	if (i > mid) {
		for (int t = j; t <= right; t++) {
			sr2[k++] = sr[t];
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sr2[k++] = sr[t];
		}
	}

	for (int t = left; t <= right; t++) {
		sr[t] = sr2[t];
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
		scanf("%d", &sr[n]);
	}

	MergeSort(0, N - 1);

	int left = 0;
	int right = N - 1;

	for (; left < right; left += 2) {
		if (sr[left] < 1 && sr[left + 1] < 1) {
			ans += sr[left] * sr[left + 1];
		}
		else {
			break;
		}
	}

	for (; right > 0; right -= 2) {
		if (sr[right] > 1 && sr[right - 1] > 1) {
			ans += sr[right] * sr[right - 1];
		}
		else {
			break;
		}
	}

	for (; right >= left; right--) {
		ans += sr[right];
	}

	printf("%lld", ans);

	return 0;
}
