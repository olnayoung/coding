#include<cstdio>

int N, start, finish;
int map[100000][2], ans[100000][2];

int merge(int left, int mid, int right, int p) {
	int i, j, k;
	i = left;	j = mid + 1;	k = left;

	while ((i <= mid) && (j <= right)) {
		if (map[i][p] <= map[j][p]) {
			ans[k][0] = map[i][0];
			ans[k++][1] = map[i++][1];
		}
		else {
			ans[k][0] = map[j][0];
			ans[k++][1] = map[j++][1];
		}
	}

	if (i > mid) {
		for (int t = j; t <= right; t++) {
			ans[k][0] = map[t][0];
			ans[k++][1] = map[t][1];
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			ans[k][0] = map[t][0];
			ans[k++][1] = map[t][1];
		}
	}

	for (int t = left; t <= right; t++) {
		map[t][0] = ans[t][0];
		map[t][1] = ans[t][1];
	}

	return 0;
}

int MergeSort(int left, int right, int p) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(left, mid, p);
		MergeSort(mid + 1, right, p);
		merge(left, mid, right, p);
	}

	return 0;
}

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < 2; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	MergeSort(0, N - 1, 1);

	while (finish < N - 1) {
		if (map[finish][1] != map[finish + 1][1]) {
			start++;	finish++;
		}
		start = finish;

		while (map[finish][1] == map[finish + 1][1])	finish++;

		MergeSort(start, finish, 0);
	}

	for (int y = 0; y < N; y++) {
		printf("%d %d\n", map[y][0], map[y][1]);
	}

	return 0;
}
