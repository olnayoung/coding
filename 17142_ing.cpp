#include <iostream>

int N, M, num_virus, num_blanks;
int map[50][50], visit[50][50];
int virus_x[10], virus_y[10];
int min = 10000;
int que_x[2500], que_y[2500], start, finish;
int save[10];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int print() {
	printf("\n\n");
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			printf("%d ", visit[y][x]);
		}
		printf("\n");
	}

	return 0;
}

int clear() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			visit[y][x] = 0;
		}
	}

	start = 0;
	finish = 0;

	return 0;
}

int time() {
	clear();

	for (int x = 0; x < M; x++) {
		que_y[x] = virus_y[save[x]];
		que_x[x] = virus_x[save[x]];
		visit[virus_y[save[x]]][virus_x[save[x]]] = 1;
	}
	finish += M;

	int vir_y, vir_x, new_y, new_x, max = 0, count_blank = 0;

	while (start < finish) {
		vir_y = que_y[start];	vir_x = que_x[start];
		start++;

		for (int t = 0; t < 4; t++) {
			new_y = vir_y + dy[t];	new_x = vir_x + dx[t];

			if ((new_y > -1) && (new_y < N) && (new_x > -1) && (new_x < N) && (visit[new_y][new_x] == 0) && (map[new_y][new_x] == 0)) {
				visit[new_y][new_x] = visit[vir_y][vir_x] + 1;
				que_y[finish] = new_y;	que_x[finish] = new_x;
				finish++;
				count_blank++;

				max = (visit[new_y][new_x] > max) ? visit[new_y][new_x] : max;
			}
		}

	}
  
	if (count_blank == num_blanks) {
		min = (min < max) ? min : max;
	}

	return 0;
}

int spread(int srt, int num) {

	for (int x = srt; x < num_virus - M + num + 1; x++) {
		save[num] = x;

		if (num+1 == M)	time();
		if (num+1 < M)	spread(x + 1, num + 1);
	}

	return 0;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &map[y][x]);

			if (map[y][x] == 2) {
				virus_y[num_virus] = y;
				virus_x[num_virus] = x;
				num_virus++;
			}

			else if (map[y][x] == 0) num_blanks++;
		}
	}

	if (num_blanks == 0)	min = 1;
	else spread(0, 0);

	if (min == 10000)	min = 0;
	printf("%d", min-1);

	return 0;
}
