#include<iostream>
#define max 99999

int N, sum;
int status = 0;
int map[20][20], visit[3][16][16], check[3][3][16][16]; // past, cur, y, x
int que[max][3], start, finish;

int move(int cur_y, int cur_x, int cur) {
	if (cur == 0) {
		if ((cur_x + 2 < N) && (map[cur_y][cur_x + 2] == 0)) {
			if (check[0][0][cur_y][cur_x + 2] == 0) {
				que[finish][0] = cur_y;	que[finish][1] = cur_x + 1;	que[finish][2] = 0;	finish++;
				visit[0][cur_y][cur_x + 2] += visit[0][cur_y][cur_x + 1];
				check[0][0][cur_y][cur_x + 2] = 1;
			}
		}
		if ((cur_y + 1 < N) && (cur_x + 2 < N) && (map[cur_y][cur_x + 2] == 0) && (map[cur_y + 1][cur_x + 1] == 0) && (map[cur_y + 1][cur_x + 2] == 0)) {
			if (check[0][2][cur_y + 1][cur_x + 2] == 0) {
				que[finish][0] = cur_y;	que[finish][1] = cur_x + 1;	que[finish][2] = 2;	finish++;
				visit[2][cur_y + 1][cur_x + 2] += visit[0][cur_y][cur_x + 1];
				check[0][2][cur_y + 1][cur_x + 2] = 1;
			}
		}
	}
	else if (cur == 1) {
		if ((cur_y + 2 < N) && (map[cur_y + 2][cur_x] == 0)) {
			if (check[1][1][cur_y + 2][cur_x] == 0) {
				que[finish][0] = cur_y + 1;	que[finish][1] = cur_x;	que[finish][2] = 1;	finish++;
				visit[1][cur_y + 2][cur_x] += visit[1][cur_y + 1][cur_x];
				check[1][1][cur_y + 2][cur_x] = 1;
			}
		}
		if ((cur_y + 2 < N) && (cur_x + 1 < N) && (map[cur_y + 1][cur_x + 1] == 0) && (map[cur_y + 2][cur_x] == 0) && (map[cur_y + 2][cur_x + 1] == 0)) {
			if (check[1][2][cur_y + 2][cur_x + 1] == 0) {
				que[finish][0] = cur_y + 1;	que[finish][1] = cur_x;	que[finish][2] = 2;	finish++;
				visit[2][cur_y + 2][cur_x + 1] += visit[1][cur_y + 1][cur_x];
				check[1][2][cur_y + 2][cur_x + 1] = 1;
			}
		}
	}
	else if (cur == 2) {
		if ((cur_y + 1 < N) && (cur_x + 2 < N) && (map[cur_y + 1][cur_x + 2] == 0)) {
			if (check[2][0][cur_y + 1][cur_x + 2] == 0) {
				que[finish][0] = cur_y + 1;	que[finish][1] = cur_x + 1;	que[finish][2] = 0;	finish++;
				visit[0][cur_y + 1][cur_x + 2] += visit[2][cur_y + 1][cur_x + 1];
				check[2][0][cur_y + 1][cur_x + 2] = 1;
			}
		}
		if ((cur_y + 2 < N) && (cur_x + 1 < N) && (map[cur_y + 2][cur_x + 1] == 0)) {
			if (check[2][1][cur_y + 2][cur_x + 1] == 0) {
				que[finish][0] = cur_y + 1;	que[finish][1] = cur_x + 1;	que[finish][2] = 1;	finish++;
				visit[1][cur_y + 2][cur_x + 1] += visit[2][cur_y + 1][cur_x + 1];
				check[2][1][cur_y + 2][cur_x + 1] = 1;
			}
		}
		if ((cur_y + 2 < N) && (cur_x + 2 < N) && (map[cur_y + 1][cur_x + 2] == 0) && (map[cur_y + 2][cur_x + 1] == 0) && (map[cur_y + 2][cur_x + 2] == 0)) {
			if (check[2][2][cur_y + 2][cur_x + 2] == 0) {
				que[finish][0] = cur_y + 1;	que[finish][1] = cur_x + 1;	que[finish][2] = 2;	finish++;
				visit[2][cur_y + 2][cur_x + 2] += visit[2][cur_y + 1][cur_x + 1];
				check[2][2][cur_y + 2][cur_x + 2] = 1;
			}
		}
	}

	return 0;
}

int count() {
	que[0][0] = 0;	que[0][1] = 0;	que[0][2] = 0; finish++;
	int y, x;
	visit[0][0][1] = 1;

	while (start < finish) {
		y = que[start][0];	x = que[start][1];	status = que[start][2];	start++;

		move(y, x, status);
	}

	return 0;
}

int main(){
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	count();

	for (int t = 0; t < 3; t++) {
		sum += visit[t][N - 1][N - 1];
	}

	printf("%d", sum);

	return 0;
}
