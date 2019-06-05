#include <cstdio>
#define max 99999

int N, K, L, time;
int map[100][100];
int move_time[100], cur_move_time;
char direc[100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int snake_y[max], snake_x[max], start, finish;

int print() {
	printf("\n\n");
	printf("%d\n", time);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}
	return 0;
}

int move() {
	int dir = 0;

	snake_y[finish] = 0;	snake_x[finish] = 0;
	map[0][0] = 2; // snake = 2
	finish++;

	int new_y, new_x;

	while (1) {
		new_y = snake_y[finish - 1] + dy[dir];	new_x = snake_x[finish - 1] + dx[dir];
		time++;

		if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N)) {
			if (map[new_y][new_x] == 0) {
				map[new_y][new_x] = 2;
				snake_y[finish] = new_y;	snake_x[finish] = new_x;
				finish++;

				map[snake_y[start]][snake_x[start]] = 0;
				start++;
			}
			else if (map[new_y][new_x] == 1) {
				map[new_y][new_x] = 2;
				snake_y[finish] = new_y;	snake_x[finish] = new_x;
				finish++;
			}
			else if (map[new_y][new_x] == 2) {
				break;
			}

			if (move_time[cur_move_time] == time) {
				if (direc[cur_move_time] == 'D')	dir = (dir + 1) % 4;
				else dir = (dir + 3) % 4;
				cur_move_time++;
			}
		}
		else {
			break;
		}
	}

	return 0;
}

int main() {
	scanf("%d %d", &N, &K);

	int y, x;
	char temp;
	for (int t = 0; t < K; t++) {
		scanf("%d", &y);	scanf("%d", &x);
		map[y-1][x-1] = 1;
	}

	scanf("%d", &L);
	for (int t = 0; t < L; t++) {
		scanf("%d", &move_time[t]);	scanf("%1c", &temp);	scanf("%1c", &direc[t]);
	}

	move();

	printf("%d", time);

	return 0;
}
