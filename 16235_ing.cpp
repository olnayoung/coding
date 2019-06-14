#include <cstdio>
#define max 999999

int N, M, K, tree_num[10][10], changed[10][10], sum;
int map[10][10], A[10][10], tree_map[10][10][max], dead;
int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int print() {
	printf("\n-------------map--------------\n");
	printf("\n\n");
	for (int n = 0; n < N; n++) {
		for (int nn = 0; nn < N; nn++) {
			printf("%d ", map[n][nn]);
		}
		printf("\n");
	}
	printf("\n-------------TREE--------------\n");

	printf("\n\n");
	for (int n = 0; n < N; n++) {
		for (int nn = 0; nn < N; nn++) {
			printf("%d ", tree_num[n][nn]);
		}
		printf("\n");
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (tree_num[y][x] > 0) {
				printf("y: %d, x: %d\n", y, x);
				for (int t = 0; t < tree_num[y][x]; t++) {
					printf("%d ", tree_map[y][x][t]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}

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

int Partition(int y, int x, int left, int right) {
	int pivot = tree_map[y][x][left];
	int low = left + 1;
	int high = right;
	int temp;

	while (low <= high) {
		while ((pivot >= tree_map[y][x][low]) && (low <= right))	low++;
		while ((pivot <= tree_map[y][x][high]) && (high >= left + 1))	high--;
		if (low <= high) {
			temp = tree_map[y][x][low];
			tree_map[y][x][low] = tree_map[y][x][high];
			tree_map[y][x][high] = temp;
		}
	}
	temp = tree_map[y][x][left];
	tree_map[y][x][left] = tree_map[y][x][high];
	tree_map[y][x][high] = temp;

	return high;

}

void QuickSort(int y, int x, int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(y, x, left, right);
		QuickSort(y, x, left, pivot - 1);
		QuickSort(y, x, pivot + 1, right);
	}
}

int order() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			QuickSort(y, x, 0, tree_num[y][x] - 1);
		}
	}
	return 0;
}

int spring() {
	order(); 
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
							tree_map[new_y][new_x][tree_num[new_y][new_x] + changed[new_y][new_x]] = 1;
							changed[new_y][new_x]++;
						}
					}
				}
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			tree_num[y][x] += changed[y][x];
		}
	}

	return 0;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int n = 0; n < N; n++) {
		for (int nn = 0; nn < N; nn++) {
			scanf("%d", &A[n][nn]);
		}
	}

	int a, b, c;
	for (int m = 0; m < M; m++) {
		scanf("%d %d %d", &a, &b, &c);
		tree_map[a - 1][b - 1][tree_num[a][b]] = c;
		tree_num[a - 1][b - 1]++;
	}

	init();

	for (int k = 0; k < K; k++) {
		spring();
		//print();
		fall();
		//print();
	}

	calcul();

	printf("%d", sum);

	return 0;
}
