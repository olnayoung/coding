#include<iostream>

int N, max, out, score;
int map[50][9];
int order[9], ground[3];

int calcul() {
	score = 0;
	int x = 0;

	for (int y = 0; y < N; y++) {
		out = 0;	ground[0] = -1;	ground[1] = -1;	ground[2] = -1;

		while (out < 3) {
			if (map[y][order[x]] == 0) {
				out++;
			}
			else if (map[y][order[x]] == 1) {
				if (ground[2] != -1) score++;
				ground[2] = ground[1];	ground[1] = ground[0];	ground[0] = x;
			}
			else if (map[y][order[x]] == 2) {
				if (ground[2] != -1) score++;
				if (ground[1] != -1) score++;
				ground[2] = ground[0];	ground[1] = x;	ground[0] = -1;
			}
			else if (map[y][order[x]] == 3) {
				if (ground[2] != -1) score++;
				if (ground[1] != -1) score++;
				if (ground[0] != -1) score++;
				ground[2] = x;	ground[1] = -1;	ground[0] = -1;
			}
			else if (map[y][order[x]] == 4) {
				if (ground[2] != -1) score++;
				if (ground[1] != -1) score++;
				if (ground[0] != -1) score++;
				score++;
				ground[2] = -1;	ground[1] = -1;	ground[0] = -1;
			}
			x++;
			if (x == 9)	x = 0;
		}
	}

	max = (max > score) ? max : score;

	return 0;
}

int get_order() {
	order[3] = 0;

	for (int a = 0; a < 9; a++) {
		if (a == 0) continue;
		order[0] = a;

		for (int b = 0; b < 9; b++) {
			if ((b == 0) || (b == order[0])) continue;
			order[1] = b;

			for (int c = 0; c < 9; c++) {
				if ((c == 0) ||(c == order[0]) || (c == order[1])) continue;
				order[2] = c;

				for (int d = 0; d < 9; d++) {
					if ((d == 0) || (d == order[0]) || (d == order[1]) || (d == order[2])) continue;
					order[4] = d;

					for (int e = 0; e < 9; e++) {
						if ((e == 0) || (e == order[0]) || (e == order[1]) || (e == order[2]) || (e== order[4])) continue;
						order[5] = e;

						for (int f = 0; f < 9; f++) {
							if ((f == 0) || (f == order[0]) || (f == order[1]) || (f == order[2]) || (f == order[4]) || (f == order[5])) continue;
							order[6] = f;

							for (int g = 0; g < 9; g++) {
								if ((g == 0) || (g == order[0]) || (g == order[1]) || (g == order[2]) || (g == order[4]) || (g == order[5]) || (g == order[6])) continue;
								order[7] = g;

								for (int h = 0; h < 9; h++) {
									if ((h == 0) || (h == order[0]) || (h == order[1]) || (h == order[2]) || (h == order[4]) || (h == order[5]) || (h == order[6]) || (h == order[7])) continue;
									order[8] = h;

									calcul();
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < 9; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	get_order();

	printf("%d", max);

	return 0;
}
