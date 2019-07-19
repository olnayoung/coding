#include<iostream>
#define len 100
using namespace std;

int N, start, finish;
int map[100000][2], ans[100000][2];
char name[100000][len], c_ans[100000][len];

int merge(int left, int mid, int right, int p) {
	int i, j, k;
	i = left;	j = mid + 1;	k = left;

	while ((i <= mid) && (j <= right)) {
		if (map[i][p] <= map[j][p]) {
			for (int tt = 0; tt < len; tt++) {
				c_ans[k][tt] = name[i][tt];
			}
			ans[k][0] = map[i][0];
			ans[k++][1] = map[i++][1];
		}
		else {
			for (int tt = 0; tt < len; tt++) {
				c_ans[k][tt] = name[j][tt];
			}
			ans[k][0] = map[j][0];
			ans[k++][1] = map[j++][1];
		}
	}

	if (i > mid) {
		for (int t = j; t <= right; t++) {
			for (int tt = 0; tt < len; tt++) {
				c_ans[k][tt] = name[t][tt];
			}
			ans[k][0] = map[t][0];
			ans[k++][1] = map[t][1];
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			for (int tt = 0; tt < len; tt++) {
				c_ans[k][tt] = name[t][tt];
			}
			ans[k][0] = map[t][0];
			ans[k++][1] = map[t][1];
		}
	}

	for (int t = left; t <= right; t++) {
		for (int tt = 0; tt < len; tt++) {
			name[t][tt] = c_ans[t][tt];
		}
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
		scanf("%d", &map[y][0]);	map[y][1] = y;
		scanf("%s", name[y]);
		getchar();
	}

	MergeSort(0, N - 1, 0);

	while (finish < N - 1) {
		if (map[finish][0] != map[finish + 1][0]) {
			start++;	finish++;
		}
		start = finish;

		while (map[finish][0] == map[finish + 1][0])	finish++;

		MergeSort(start, finish, 1);
	}

	for (int y = 0; y < N; y++) {
		printf("%d %s\n", map[y][0], name[y]);
		//cout << map[y][0] << " " << name[y] << "\n";
	}

	return 0;
}
