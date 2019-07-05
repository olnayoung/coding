#include<iostream>
#define max 999999

int N, M, hour_1, hour_2, time, ori;
int map[100][100], visit[100][100], air[100][100];
int que[max][2], start, finish;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int search() {
	start = 0;	finish = 0;
	que[finish][0] = 0;	que[finish][1] = 0;	finish++;
	visit[0][0] = 1;

	int y, x, new_y, new_x;
	while (start < finish) {
		y = que[start][0];	x = que[start][1];	start++;

		for (int t = 0; t < 4; t++) {
			new_y = y + dy[t];	new_x = x + dx[t];

			if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < M) && (visit[new_y][new_x] == 0) && (map[y][x] == 0)) {
				visit[new_y][new_x] = 1;

				if (map[new_y][new_x] == 1)	
					air[new_y][new_x]++;
				else {
					que[finish][0] = new_y;	que[finish][1] = new_x;	finish++;
				}
			}
		}
	}
	
	return 0;
}

int remove() {
	hour_2 = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			visit[y][x] = 0;

			if (air[y][x] > 0) {
				map[y][x] = 0;
				air[y][x] = 0;
			}

			if (map[y][x] == 1)	hour_2++;
		}
	}

	return 0;
}

int main(){
	scanf("%d %d", &N, &M);

	int check = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 1)	{
				check = 1;
				ori++;
			}
		}
	}

	while (1) {
		time++;
		hour_1 = hour_2;
		search();
		remove();

		if (hour_2 == 0)	break;
	}

	if (check == 0) {
		time = 0;
		hour_1 = 0;
	}
	if (time == 1) {
		hour_1 = ori;
	}

	printf("%d\n%d", time, hour_1);

	return 0;
}
