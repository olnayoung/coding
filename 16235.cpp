#include <cstdio>
#define max 999999

int N, M, K, tree_num[10][10], changed[10][10];
long long sum;
int map[10][10], A[10][10], tree_map[10][10][max], dead;
int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int calcul() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			sum += tree_num[y][x];
		}
	}
	return 0;
}

int init() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x] = 5;
		}
	}
	return 0;
}

int spring() {
	int num;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			num = 0;
			dead = 0;
			for (int j = 0; j < tree_num[y][x]; j++) {
				if (map[y][x] >= tree_map[y][x][j]) {
					map[y][x] -= tree_map[y][x][j];
					tree_map[y][x][j]++;
				}
				else {
					dead += (tree_map[y][x][j] / 2); // summer
					tree_map[y][x][j] = 0;
					num--;
				}
			}
			tree_num[y][x] += num;
			map[y][x] += dead;
			map[y][x] += A[y][x]; // winter

			changed[y][x] = 0; // clear
		}
	}
	return 0;
}

int fall() {
	int new_y, new_x;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			for (int j = 0; j < tree_num[y][x]; j++) {
				if (tree_map[y][x][j] % 5 == 0) {
					for (int t = 0; t < 8; t++) {
						new_y = y + dy[t];	new_x = x + dx[t];
						if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N)) {
							changed[new_y][new_x]++;
						}
					}
				}
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (changed[y][x] > 0) {
				for (int t = tree_num[y][x] - 1; t >= 0; t--) {
					tree_map[y][x][t + changed[y][x]] = tree_map[y][x][t];
				}
				for (int t = 0; t < changed[y][x]; t++) {
					tree_map[y][x][t] = 1;
				}
				tree_num[y][x] += changed[y][x];
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &A[y][x]);
		}
	}

	int a, b, c;
	for (int m = 0; m < M; m++) {
		scanf("%d %d %d", &a, &b, &c);
		tree_map[a - 1][b - 1][tree_num[a - 1][b - 1]] = c;
		tree_num[a - 1][b - 1]++;
	}

	init();

	for (int k = 0; k < K; k++) {
		spring();
		fall();
	}

	calcul();

	printf("%lld", sum);

	return 0;
}
