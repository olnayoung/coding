#include <cstdio>
#define max 10000000

int N, M, K, tree_num, dead_num, tree_end, dead_end; // num = 실제 갯수, end = 끝 array 번호
int map[10][10], A[10][10];
int tree[max][3], dead_tree[max][3];
long long tree_y[max], tree_x[max], tree_age[max];
long long dead_tree[max], dead_tree[max], dead_tree[max];
int dx[8] = { 0, 0, 1, -1, 1, -1 , 1, -1};
int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };

int print() {
	printf("\n\n");
	for (int n = 0; n < N; n++) {
		for (int nn = 0; nn < N; nn++) {
			printf("%d ", map[n][nn]);
		}
		printf("\n");
	}

	return 0;
}

int init() {
	for (int n = 0; n < N; n++) {
		for (int nn = 0; nn < N; nn++) {
			map[n][nn] = 5;
		}
	}
	return 0;
}

int order() {
	int temp;

	for (int a = 0; a < tree_end; a++) {
		for (int b = 0; b < tree_end; b++) {
			if (tree[b][2] > tree[b + 1][2]) {
				temp = tree[b][2];	tree[b][2] = tree[b + 1][2];	tree[b + 1][2] = temp;
				temp = tree[b][1];	tree[b][1] = tree[b + 1][1];	tree[b + 1][1] = temp;
				temp = tree[b][0];	tree[b][0] = tree[b + 1][0];	tree[b + 1][0] = temp;
			}
		}
	}

	return 0;
}

int move_tree() {
	int temp;
	for (int a = 0; a < tree_end; a++) {
		if (tree[a][2] == 0) {
			temp = 0;
			while (1) {
				if (tree[a + temp + 1][2] != 0)	break;
				temp++;
			}
			for (int b = a; b < tree_end; b++) {
				tree[b][0] = tree[b + temp + 1][0];
				tree[b][1] = tree[b + temp + 1][1];
				tree[b][2] = tree[b + temp + 1][2];
			}
		}
	}

	tree[tree_num][0] = 0;	tree[tree_num][1] = 0;	tree[tree_num][2] = 0;

	tree_end = tree_num;

	return 0;
}

int spring() {
	for (int i = 0; i < tree_end; i++) {
		if (map[tree[i][0]][tree[i][1]] >= tree[i][2]) {
			map[tree[i][0]][tree[i][1]] -= tree[i][2];
			tree[i][2]++;
		}
		else {
			tree_num--;
			dead_tree[dead_num][0] = tree[i][0];
			dead_tree[dead_num][1] = tree[i][1];
			dead_tree[dead_num][2] = tree[i][2];
			dead_num++;
			tree[i][2] = 0;
		}
	}

	return 0;
}

int summer() {
	for (int i = 0; i < dead_num; i++) {
		map[dead_tree[i][0]][dead_tree[i][1]] += (dead_tree[i][2] / 2);
	}

	dead_num = 0;
	return 0;
}

int fall() {
	move_tree();

	int new_y, new_x, temp_end = tree_end;

	for (int i = 0; i < temp_end; i++) {
		if (tree[i][2] % 5 == 0) {
			for (int t = 0; t < 8; t++) {
				new_y = tree[i][0] + dy[t];	new_x = tree[i][1] + dx[t];

				if ((new_y < N) && (new_x < N) && (new_y > -1) && (new_x > -1)) {
					tree[tree_end][0] = new_y;
					tree[tree_end][1] = new_x;
					tree[tree_end][2] = 1;
					tree_end++;
					tree_num++;
				}
			}
		}
	}

	order();
	move_tree();

	return 0;
}

int winter() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x] += A[y][x];
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

	for (int m = 0; m < M; m++) {
		scanf("%d %d %d", &tree[m][1], &tree[m][0], &tree[m][2]);
		tree[m][0]--;	 tree[m][1]--;
		tree_num++;
		tree_end++;
	}

	init();

	for (int k = 0; k < K; k++) {
		spring();
		summer();
		fall();
		winter();
	}

	printf("%d", tree_num);

	return 0;
}
