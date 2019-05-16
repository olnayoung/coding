#include <iostream>
#define MAX 99999

int r, c, k, row, col, t;
int map[110][110];
int count[MAX], same[MAX];
int max_num, max_col, max_row;

int sort_row() {
	for (int y = 0; y < row; y++) {
		int temp = 0;
		max_num = 0;
		for (int x = 0; x < col; x++) {
			count[map[y][x]]++;
			max_num = (max_num > map[y][x]) ? max_num : map[y][x];
		}

		for (int t = 1; t < 100; t++) {
			for (int x = 1; x < max_num + 1; x++) {
				if (count[x] == t) {
					map[y][temp] = x;
					map[y][temp+1] = count[x];
					temp += 2;
					count[x] = 0;
				}
			}
		}
		max_col = (max_col > temp) ? max_col : temp;
		max_col = (max_col > 100) ? 99 : max_col;

		for (int x = temp; x < max_col; x++) {
			map[y][x] = 0;
		}
	}
	return 0;
}

int sort_col() {
	for (int x = 0; x < col; x++) {
		int temp = 0;
		max_num = 0;
		for (int y = 0; y < row; y++) {
			count[map[y][x]]++;
			max_num = (max_num > map[y][x]) ? max_num : map[y][x];
		}

		for (int t = 1; t < 100; t++) {
			for (int y = 1; y < max_num + 1; y++) {
				if (count[y] == t) {
					map[temp][x] = y;
					map[temp+1][x] = count[y];
					temp += 2;
					count[y] = 0;
				}
			}
		}
		max_row = (max_row > temp) ? max_row : temp;
		max_row = (max_row > 100) ? 100 : max_row;

		for (int y = temp; y < max_row; y++) {
			map[y][x] = 0;
		}
	}
	return 0;
}

int expand() {
	if (row >= col)	{
		sort_row();
		col = max_col;
	}
	else {
		sort_col();
		row = max_row;
	}
	return 0;
}

int main() {
	scanf("%d %d %d", &r, &c, &k);
	r--; c--;

	row = 3;		col = 3;
	max_row = row;	max_col = col;

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	while (map[r][c] != k) {
		if (t == 100) {
			t = -1;
			break;
		}
		expand();
		t++;
	}
	printf("%d", t);

	return 0;
}
