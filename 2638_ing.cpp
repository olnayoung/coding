#include <cstdio>
#define max 9999999

int N, M, time, check, count, start, end, check_x, check_b, temp;
int map[100][100];
int boundary[100][100];
int dx[4] = { -1, 1, 1, -1 };
int dy[4] = { 1, -1, 1, -1 };

int print() {
	printf("\n"); printf("\n");
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}
	return 0;
}

int clear() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			boundary[y][x] = -1;
		}
	}

	return 0;
}

int search() {
	clear();

	check_x = 0;

	for (int x = 0; x < M; x++) {
		check = 0;
		for (int y = 0; y < N; y++) {
			if ((map[y][x] == 1) && (check_x == 0)) {
				start = x;
				check_x = 1;
			}

			if ((map[y][x] == 1) && (check == 0)) {
				check = 1;
				boundary[x][0] = y;
				end = x;
			}
			else if ((map[y][x] == 1) && (check == 1)) {
				boundary[x][1] = y;
				end = x;
			}
		}
	}

	temp = boundary[start][1];
	int temp_y = 0;

	for (int y = 0; y < N; y++) {
		if (map[start][y] == 1) {
			boundary[start][temp_y] = y;
			temp_y++;
		}

		if (y == temp) {
			boundary[start][temp_y] = y;
			break;
		}
	}

	temp = boundary[start][1];
	temp_y = 0;

	for (int y = 0; y < N; y++) {
		if (map[end][y] == 1) {
			boundary[end][temp_y] = y;
			temp_y++;
		}

		if (y == temp) {
			boundary[end][temp_y] = y;
			break;
		}
	}

	return 0;
}

int remove() {
	int new_y, new_x;
	check = 0;

	for (int x = 0; x < M; x++) {
		for (int aa = 0; aa < 2; aa++) {
			if (boundary[x][aa] != -1) {
				check_b = 0;

				for (int t = 0; t < 4; t++) {
					new_y = boundary[x][aa] + dy[t];	new_x = x + dx[t];

					if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < M)) {
						if (map[new_y][new_x] == 0) {
							check_b++;
						}
					}
				}

				if (check_b > 1) {
					map[new_y][new_x] = 0;
					boundary[new_x][0] = -1;
					check = 1;
				}
			}
		}
	}

	if (check == 1)	time++;
	else return 1;

	return 0;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	while (1) {
		search();
		temp = remove();
		if (temp == 1)	break;
	}

	printf("%d", time);

	return 0;
}
