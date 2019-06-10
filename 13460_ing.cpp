#include <cstdio>
#define max 1000000

int N, M, min = 11;
char map[10][10];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int red_y, red_x, blue_y, blue_x;
int past_red_y[10], past_red_x[10], past_blue_y[10], past_blue_x[10];

int print() {
	printf("\n\n");
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			printf("%c", map[y][x]);
		}
		printf("\n");
	}
	return 0;
}

int move_back(int num) {
	map[red_y][red_x] = '.';
	map[past_red_y[num]][past_red_x[num]] = 'R';
	map[blue_y][blue_x] = '.';
	map[past_blue_y[num]][past_blue_x[num]] = 'B';

	red_y = past_red_y[num];	red_x = past_red_x[num];	blue_y = past_blue_y[num];	blue_x = past_blue_x[num];
	return 0;
}

int move_red(int way) {
	int ddy = dy[way], ddx = dx[way];

	if (map[red_y + ddy][red_x + ddx] == '.') {
		map[red_y][red_x] = '.';
		red_y += ddy;	red_x += ddx;
		map[red_y][red_x] = 'R';
	}
	return 0;
}

int move_blue(int way) {
	int ddy = dy[way], ddx = dx[way];

	if (map[blue_y + ddy][blue_x + ddx] == '.') {
		map[blue_y][blue_x] = '.';
		blue_y += ddy;	blue_x += ddx;
		map[blue_y][blue_x] = 'B';
	}
	return 0;
}

int roll_red(int num, int way) {
	int ddy = dy[way], ddx = dx[way];

	while (1) {
		if (map[red_y + ddy][red_x + ddx] == '.') move_red(way);
		else if (map[red_y + ddy][red_x + ddx] == '#' || map[red_y + ddy][red_x + ddx] == 'B')	break;
		else if (map[red_y + ddy][red_x + ddx] == 'O') {
			min = (num > min) ? min : num;
			return 1;
		}
	}

	return 0;
}

int roll_blue(int num, int way) {
	int ddy = dy[way], ddx = dx[way];

	while (1) {
		if (map[blue_y + ddy][blue_x + ddx] == '.')	move_blue(way);
		else if (map[blue_y + ddy][blue_x + ddx] == '#' || map[blue_y + ddy][blue_x + ddx] == 'R')	break;
		else if (map[blue_y + ddy][blue_x + ddx] == 'O')	return 1;
	}

	return 0;
}


int roll(int num) {
	if (num == 10) {
		return 0;
	}

	int temp;

	if (red_y == blue_y) { // ->
		if (red_x > blue_x) {
			past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
			temp = roll_red(num, 0);	if (temp == 1)	return 0;
			temp = roll_blue(num, 0);	if (temp == 1)	return 0;
			roll(num + 1);
			move_back(num);
		}
		else {
			past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
			temp = roll_blue(num, 0);	if (temp == 1)	return 0;
			temp = roll_red(num, 0);	if (temp == 1)	return 0;
			roll(num + 1);
			move_back(num);
		}
	}
	else {
		past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
		temp = roll_blue(num, 0);	if (temp == 1)	return 0;
		temp = roll_red(num, 0);	if (temp == 1)	return 0;
		roll(num + 1);
		move_back(num);
	}

	if (red_x == blue_x) { // down
		if (red_y > blue_y) {
			past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
			temp = roll_red(num, 1);	if (temp == 1)	return 0;
			temp = roll_blue(num, 1);	if (temp == 1)	return 0;
			roll(num + 1);
			move_back(num);
		}
		else {
			past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
			temp = roll_blue(num, 1);	if (temp == 1)	return 0;
			temp = roll_red(num, 1);	if (temp == 1)	return 0;
			roll(num + 1);
			move_back(num);
		}
	}
	else {
		past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
		temp = roll_blue(num, 1);	if (temp == 1)	return 0;
		temp = roll_red(num, 1);	if (temp == 1)	return 0;
		roll(num + 1);
		move_back(num);
	}

	if (red_y == blue_y) { // <-
		if (red_x < blue_x) {
			past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
			temp = roll_red(num, 2);	if (temp == 1)	return 0;
			temp = roll_blue(num, 2);	if (temp == 1)	return 0;
			roll(num + 1);
			move_back(num);
		}
		else {
			past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
			temp = roll_blue(num, 2);	if (temp == 1)	return 0;
			temp = roll_red(num, 2);	if (temp == 1)	return 0;
			roll(num + 1);
			move_back(num);
		}
	}
	else {
		past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
		temp = roll_blue(num, 2);	if (temp == 1)	return 0;
		temp = roll_red(num, 2);	if (temp == 1)	return 0;
		roll(num + 1);
		move_back(num);
	}

	if (red_x == blue_x) { // up
		if (red_y < blue_y) {
			past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
			temp = roll_red(num, 3);	if (temp == 1)	return 0;
			temp = roll_blue(num, 3);	if (temp == 1)	return 0;
			roll(num + 1);
			move_back(num);
		}
		else {
			past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
			temp = roll_blue(num, 3);	if (temp == 1)	return 0;
			temp = roll_red(num, 3);	if (temp == 1)	return 0;
			roll(num + 1);
			move_back(num);
		}
	}
	else {
		past_red_y[num] = red_y;	past_red_x[num] = red_x;	past_blue_y[num] = blue_y;	past_blue_x[num] = blue_x;
		temp = roll_blue(num, 3);	if (temp == 1)	return 0;
		temp = roll_red(num, 3);	if (temp == 1)	return 0;
		roll(num + 1);
		move_back(num);
	}

	return 0;
}

int main() {
	scanf("%d %d", &N, &M);

	char temp;
	for (int y = 0; y < N; y++) {
		scanf("%1c", &temp);
		for (int x = 0; x < M; x++) {
			scanf("%1c", &map[y][x]);
			if (map[y][x] == 'R') {
				red_y = y;	red_x = x;
			}
			else if (map[y][x] == 'B') {
				blue_y = y;	blue_x = x;
			}
		}
	}

	roll(0);

	if (min == 11)	printf("-1");
	else printf("%d", min+1);

	return 0;
}
