#include<iostream>
#define max 99999

int N, sum;
int status = 0;
int map[20][20]; // past, cur, y, x
int que[max][3], start, finish;

int move(int cur_y, int cur_x, int cur) {
	if (cur == 0) {
		if ((cur_x + 1 < N) && (map[cur_y][cur_x + 1] == 0)) {
			que[finish][0] = cur_y;	que[finish][1] = cur_x + 1;	que[finish][2] = 0;	finish++;
			if ((cur_y == N - 1) && (cur_x + 1 == N - 1)) sum++;
		}
		if ((cur_y + 1 < N) && (cur_x + 1 < N) && (map[cur_y][cur_x + 1] == 0) && (map[cur_y + 1][cur_x] == 0) && (map[cur_y + 1][cur_x + 1] == 0)) {
			que[finish][0] = cur_y + 1;	que[finish][1] = cur_x + 1;	que[finish][2] = 2;	finish++;
			if ((cur_y + 1 == N - 1) && (cur_x + 1 == N - 1)) sum++;
		}
	}
	else if (cur == 1) {
		if ((cur_y + 1 < N) && (map[cur_y + 1][cur_x] == 0)) {
			que[finish][0] = cur_y + 1;	que[finish][1] = cur_x;	que[finish][2] = 1;	finish++;
			if ((cur_y + 1 == N - 1) && (cur_x == N - 1)) sum++;
		}
		if ((cur_y + 1 < N) && (cur_x + 1 < N) && (map[cur_y + 1][cur_x + 1] == 0) && (map[cur_y + 1][cur_x] == 0) && (map[cur_y][cur_x + 1] == 0)) {
			que[finish][0] = cur_y + 1;	que[finish][1] = cur_x + 1;	que[finish][2] = 2;	finish++;
			if ((cur_y + 1 == N - 1) && (cur_x + 1 == N - 1)) sum++;
		}
	}
	else if (cur == 2) {
		if ((cur_y < N) && (cur_x + 1 < N) && (map[cur_y][cur_x + 1] == 0)) {
			que[finish][0] = cur_y;	que[finish][1] = cur_x + 1;	que[finish][2] = 0;	finish++;
			if ((cur_y == N - 1) && (cur_x + 1 == N - 1)) sum++;
		}
		if ((cur_y + 1 < N) && (cur_x < N) && (map[cur_y + 1][cur_x] == 0)) {
			que[finish][0] = cur_y + 1;	que[finish][1] = cur_x;	que[finish][2] = 1;	finish++;
			if ((cur_y + 1 == N - 1) && (cur_x == N - 1)) sum++;
		}
		if ((cur_y + 1 < N) && (cur_x + 1 < N) && (map[cur_y + 1][cur_x + 1] == 0) && (map[cur_y][cur_x + 1] == 0) && (map[cur_y + 1][cur_x] == 0)) {
			que[finish][0] = cur_y + 1;	que[finish][1] = cur_x + 1;	que[finish][2] = 2;	finish++;
			if ((cur_y + 1 == N - 1) && (cur_x + 1 == N - 1)) sum++;
		}
	}

	return 0;
}

int count() {
	que[0][0] = 0;	que[0][1] = 1;	que[0][2] = 0; finish++;
	int y, x;

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

	printf("%d", sum);

	return 0;
}
