#include <iostream>
#define MAX 9999999

int hei, wid, M, person, eaten;
int map[1000][1000];
int shark[100000][5];
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, -1, 1, 0, 0 };
int save[100000], saved_num;

int get_fish() {
	for (int y = 0; y < hei; y++) {
		if (map[y][person] != 0) {
			eaten += shark[map[y][person]][4];
			shark[map[y][person]][4] = -1;
			map[y][person] = 0;
			break;
		}
	}
	person++;

	return 0;
}

int move_fish() {
	get_fish();

	saved_num = 0;
	for (int t = 1; t < M + 1; t++) {
		if (shark[t][4] == -1) continue;

		int new_y, new_x, direc_y, direc_x;
		new_y = shark[t][0] + dy[shark[t][3]] * shark[t][2];
		new_x = shark[t][1] + dx[shark[t][3]] * shark[t][2];

		direc_y = dy[shark[t][3]];	direc_x = dx[shark[t][3]];

		while ((new_y < 0) || (new_y >= hei)) {
			if (direc_y == 1) {
				new_y = hei * 2 - new_y - 2;
				direc_y = -1;
				shark[t][3] = 1;
			}
			else {
				new_y = -new_y;
				direc_y = 1;
				shark[t][3] = 2;
			}
		}

		while ((new_x < 0) || (new_x >= wid)) {
			if (direc_x == 1) {
				new_x = wid * 2 - new_x - 2;
				direc_x = -1;
				shark[t][3] = 4;
			}
			else {
				new_x = -new_x;
				direc_x = 1;
				shark[t][3] = 3;
			}
		}

		map[shark[t][0]][shark[t][1]] = 0;

		if (map[new_y][new_x] == 0) {
			map[new_y][new_x] = t;
			shark[t][0] = new_y;
			shark[t][1] = new_x;
		}
		else if (map[new_y][new_x] < t) {
			if (shark[map[new_y][new_x]][4] < shark[t][4]) {
				shark[map[new_y][new_x]][4] = -1;
				map[new_y][new_x] = t;
				shark[t][0] = new_y;
				shark[t][1] = new_x;
			}
			else shark[t][4] = -1;
		}
		else {
			save[saved_num] = t;
			saved_num++;
			shark[t][0] = new_y;
			shark[t][1] = new_x;
		}
	}

	for (int t = 0; t < saved_num; t++) {
		int new_y = shark[save[t]][0];
		int new_x = shark[save[t]][1];

		if (map[new_y][new_x] == 0) {
			map[new_y][new_x] = save[t];
			shark[save[t]][0] = new_y;
			shark[save[t]][1] = new_x;
		}
		else {
			if (shark[map[new_y][new_x]][4] < shark[save[t]][4]) {
				shark[map[new_y][new_x]][4] = -1;
				map[new_y][new_x] = save[t];
				shark[save[t]][0] = new_y;
				shark[save[t]][1] = new_x;
			}
			else {
				shark[save[t]][4] = -1;
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d %d %d", &hei, &wid, &M);

	for (int t = 1; t < M+1; t++) {
		scanf("%d %d %d %d %d", &shark[t][0], &shark[t][1], &shark[t][2], &shark[t][3], &shark[t][4]);
		shark[t][0]--;	shark[t][1]--;
		map[shark[t][0]][shark[t][1]] = t;
	}

	while (person < wid) {
		move_fish();
	}

	printf("%d", eaten);

	return 0;
}
