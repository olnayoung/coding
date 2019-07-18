int map[100000], ans[100000];

int merge(int left, int mid, int right) {
	int i, j, k;
	i = left;	j = mid + 1;	k = left;

	while ((i <= mid) && (j <= right)) {
		if (map[i] <= map[j]) {
			ans[k++] = map[i++];
		}
		else {
			ans[k++] = map[j++];
		}
	}

	if (i > mid) {
		for (int t = j; t <= right; t++) {
			ans[k++] = map[t];
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			ans[k++] = map[t];
		}
	}

	for (int t = left; t <= right; t++) {
		map[t] = ans[t];
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
