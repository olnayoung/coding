#include<iostream>
#define max 99999999

int map[5][5];
int saved[max], num, numbers[6], number, visit;
int new_y, new_x;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int check() {
	visit = 0;	number = 0;

	for (int t = 0; t < 6; t++) {
		number *= 10;	number += numbers[t];
	}

	for (int t = 0; t < num; t++) {
		if (saved[t] == number) {
			visit = 1;
			break;
		}
	}

	if (visit == 0) {
		saved[num] = number;
		num++;
	}

	return 0;
}

int dfs(int y, int x, int repeat) {
	if (repeat == 6) {
		check();
		return 0;
	}

	for (int t = 0; t < 4; t++) {
		new_y = y + dy[t];	new_x = x + dx[t];

		if ((new_y > -1) && (new_y < 5) && (new_x > -1) && (new_x < 5)) {
			numbers[repeat] = map[new_y][new_x];

			dfs(new_y, new_x, repeat + 1);
		}
	}

	return 0;
}

int search(int start_y, int start_x) {
	dfs(start_y, start_x, 0);

	return 0;
}

int main(){
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			dfs(y, x, 0);
		}
	}

	printf("%d", num);

	return 0;
}
