#include <iostream>

int hei, wid, r, c, K;
int new_r, new_c;
int map[25][25];
int order[1001];//   1
int dice[6];	// 3 0 2
				//   4
				//   5
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int roll_dice(int direc) {
	if (direc == 0) {
		int temp = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = dice[0];
		dice[0] = temp;
	}
	else if (direc == 1) {
		int temp = dice[3];
		dice[3] = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = temp;
	}
	else if (direc == 2) {
		int temp = dice[1];
		dice[1] = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = temp;
	}
	else {
		int temp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[0];
		dice[0] = temp;
	}
	return 0;
}

int copy() {
	for (int t = 0; t < K; t++) {
		int ord = order[t] - 1;
		new_r = r + dy[ord];
		new_c = c + dx[ord];

		if ((new_r >= hei) || (new_r < 0) || (new_c >= wid) || (new_c < 0)) continue;
		roll_dice(ord);

		if (map[new_r][new_c] == 0) {
			map[new_r][new_c] = dice[5];
		}
		else {
			dice[5] = map[new_r][new_c];
			map[new_r][new_c] = 0;
		}
		printf("%d\n", dice[0]);
		r = new_r;
		c = new_c;
	}
	return 0;
}

int main() {
	scanf("%d %d %d %d %d", &hei, &wid, &r, &c, &K);

	for (int y = 0; y < hei; y++) {
		for (int x = 0; x < wid; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	for (int t = 0; t < K; t++) {
		scanf("%d", &order[t]);
	}

	copy();

	return 0;
}
