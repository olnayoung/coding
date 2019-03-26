#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000
#define INF 99999999

char map[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
queue<int> sang_w, sang_h, fire_w, fire_h;

int hei, wid, s_w, s_h, f_w, f_h;
int f_map[MAX][MAX], time[MAX][MAX];

void clear(std::queue<int> &q) {
	std::queue<int> empty;
	std::swap(q, empty);
}

int initialize() {
	for (int x = 0; x < hei; x++) {
		for (int y = 0; y < wid; y++) {
			f_map[x][y] = INF;
			time[x][y] = 0;
		}
	}
	return 0;
}

int fire_map() {

	while (!fire_w.empty()) {
		f_w = fire_w.front();	fire_w.pop();		f_h = fire_h.front();	fire_h.pop();

		for (int x = 0; x < 4; x++) {
			int new_f_h = f_h + dy[x];
			int new_f_w = f_w + dx[x];

			if ((new_f_h >= 0) && (new_f_w >= 0) && (new_f_h < hei) && (new_f_w < wid)) {

				if ((map[new_f_h][new_f_w] != '#') && (f_map[new_f_h][new_f_w] > f_map[f_h][f_w] + 1)) {
					f_map[new_f_h][new_f_w] = f_map[f_h][f_w] + 1;
					fire_h.push(new_f_h);	fire_w.push(new_f_w);
				}
			}
		}
	}
	return 0;
}

int BFS()
{
	sang_w.push(s_w);	sang_h.push(s_h);

	while (!sang_w.empty()) {
		s_w = sang_w.front();	sang_w.pop();		s_h = sang_h.front();	sang_h.pop();

		if ((s_w == 0) || (s_w == wid - 1) || (s_h == 0) || (s_h == hei - 1)) {
			printf("%d", time[s_h][s_w] + 1);
			return 0;
		}

		for (int x = 0; x < 4; x++) {
			int new_s_h = s_h + dy[x];
			int new_s_w = s_w + dx[x];

			if ((new_s_h >= 0) && (new_s_w >= 0) && (new_s_h < hei) && (new_s_w < wid)) {
				if ((map[new_s_h][new_s_w] == '.') && (time[new_s_h][new_s_w] == 0) && (f_map[new_s_h][new_s_w] > time[s_h][s_w] + 1)) {
					sang_h.push(new_s_h);	sang_w.push(new_s_w);
					time[new_s_h][new_s_w] = time[s_h][s_w] + 1;
				}
			}
		}
	}
	printf("IMPOSSIBLE");

	return 0;
}

int main()
{
	int iter;

	scanf("%d", &iter);

	for (int x = 0; x < iter; x++) {
		scanf("%d %d", &wid, &hei);
		initialize();
		clear(fire_h);
		clear(fire_w);
		clear(sang_h);
		clear(sang_w);

		for (int i = 0; i < hei; i++) {
			scanf("%s", map[i]);
			for (int j = 0; j < wid; j++) {
				if (map[i][j] == '*') {
					fire_h.push(i);
					fire_w.push(j);
					f_map[i][j] = 0;
				}
				else if (map[i][j] == '@') {
					s_h = i;
					s_w = j;
				}
			}
		}
		fire_map();
		BFS();
		printf("\n");
	}

	return 0;
}
