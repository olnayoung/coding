#include <cstdio>
#define max 9999999

int N, M, start, finish, temp, time;
int map[100][100], air[100][100], visit[100][100];
int que[max][2];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

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

int search() {
	start = 0;
	finish = 0;

	que[finish][0] = 0;	que[finish][1] = 0;
	finish++;
	visit[0][0] = 1;

	int y, x, new_y, new_x;
	while (start != finish) {
		y = que[start][0];	x = que[start][1];
		start++;

		for (int t = 0; t < 4; t++) {
			new_y = y + dy[t];	new_x = x + dx[t];

			if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < M) && (visit[new_y][new_x] == 0)) {
				if (map[new_y][new_x] == 1) {
					air[new_y][new_x]++;
				}
				else {
					visit[new_y][new_x] = 1;
					que[finish][0] = new_y;	que[finish][1] = new_x;
					finish++;
				}
			}
		}
	}

	return 0;
}

int remove() {
	temp = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (air[y][x] > 1) {
				map[y][x] = 0;
				temp = 1;
			}
			air[y][x] = 0;
			visit[y][x] = 0;
		}
	}

	if (temp == 0)	return 1;
	else	return 0;
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
		time++;
	}

	printf("%d", time);

	return 0;
}
