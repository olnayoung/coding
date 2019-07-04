#include<iostream>
#define max 999999

int M, N;
char map[250][250];
int sq[100][4], visit[250][250], ans[2], sheep, wolf;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int que[max][2], start, finish, new_y, new_x;

int BFS(int y, int x) {
	start = 0;	finish = 0;	sheep = 0;	wolf = 0;
	que[finish][0] = y;	que[finish][1] = x;	finish++;
	visit[y][x] = 1;

	if (map[y][x] == 'o')	sheep++;
	else if (map[y][x] == 'v')	wolf++;

	while (start < finish) {
		y = que[start][0];	x = que[start][1];	start++;

		for (int t = 0; t < 4; t++) {
			new_y = y + dy[t];	new_x = x + dx[t];

			if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < M) && (visit[new_y][new_x] == 0)) {
				visit[new_y][new_x] = 1;
				que[finish][0] = new_y;	que[finish][1] = new_x;	finish++;

				if (map[new_y][new_x] == 'o')	sheep++;
				else if (map[new_y][new_x] == 'v') wolf++;
			}
		}
	}

	if (sheep > wolf) ans[0] = ans[0] + sheep;
	else ans[1] = ans[1] + wolf;

	return 0;
}

int search() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (visit[y][x] == 0) {
				BFS(y, x);
			}
		}
	}

	return 0;
}

int main(){
	scanf("%d %d", &N, &M);

	for (int y = 0; y < N; y++) {
		getchar();
		for (int x = 0; x < M; x++) {
			scanf("%1c", &map[y][x]);
			if (map[y][x] == '#')	visit[y][x] = 1;
		}
	}

	search();

	printf("%d %d", ans[0], ans[1]);

	return 0;
}
