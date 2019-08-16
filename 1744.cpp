#include <iostream>
#define len 10001

int N, sr[len], sr2[len], save;
long long ans;

int merge(int left, int mid, int right) {
	int i, j, k;
	i = left; j = mid + 1; k = left;

	while ((i <= mid) && (j <= right)) {
		if (sr[i] <= sr[j]) {
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
			sr2[k] = sr[t];
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

	for (int n = 0; n < N; n++) {
		if (sr[n] <= 0)	break;
		else if (sr[n + 1] <= 0) {
			ans += sr[n];
			save = n;
			break;
		}
		ans += (sr[n] * sr[n + 1]);
		n++;
		save = n;
	}

	if (sr[0] <= 0)	save = -1;
	for (int n = N - 1; n > save; n--) {
		if (n - 1 > save) {
			ans += (sr[n] * sr[n - 1]);
		}
		else {
			ans += sr[n];
		}
		n--;
	}

	printf("%lld", ans);

	return 0;
}
