#include<iostream>
#define max 999999

int M, N, K;
int map[100][100], sq[100][4], visit[100][100], ans[10000], num;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int que[max][2], start, finish;

int sort() {
	int temp;

	for (int y = num - 1; y > 0; y--) {
		for (int x = 0; x < y; x++) {
			if (ans[x] > ans[x + 1]) {
				temp = ans[x];
				ans[x] = ans[x + 1];
				ans[x + 1] = temp;
			}
		}
	}

	return 0;
}

int BFS(int y, int x) {
	start = 0;	finish = 0;
	que[finish][0] = y;	que[finish][1] = x;	finish++;
	ans[num]++;
	visit[y][x] = 1;

	int new_y, new_x;
	while (start < finish) {
		y = que[start][0];	x = que[start][1];	start++;

		for (int t = 0; t < 4; t++) {
			new_y = y + dy[t];	new_x = x + dx[t];

			if ((new_y > -1) && (new_y < M) && (new_x > -1) && (new_x < N)) {
				if (visit[new_y][new_x] == 0) {
					ans[num]++;
					visit[new_y][new_x] = 1;
					que[finish][0] = new_y;	que[finish][1] = new_x;	finish++;
				}
			}
		}
	}

	return 0;
}

int search() {
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (visit[y][x] == 0) {
				BFS(y, x);
				num++;
			}
		}
	}
	return 0;
}

int make_visit() {
	for (int t = 0; t < K; t++) {
		for (int y = sq[t][0]; y < sq[t][2]; y++) {
			for (int x = sq[t][1]; x < sq[t][3]; x++) {
				visit[y][x] = 1;
			}
		}
	}

	return 0;
}

int main(){
	scanf("%d %d %d", &M, &N, &K);

	for (int y = 0; y < K; y++) {
		scanf("%d %d %d %d", &sq[y][1], &sq[y][0], &sq[y][3], &sq[y][2]);
	}

	make_visit();
	search();
	sort();

	printf("%d\n", num);
	for (int t = 0; t < num; t++) {
		printf("%d ", ans[t]);
	}

	return 0;
}
