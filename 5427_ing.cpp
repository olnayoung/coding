#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000

char map[MAX][MAX];
//queue<int> sang_w, sang_h, fire_w, fire_h;
queue<int> sang_w;
queue<int> sang_h;
queue<int> fire_w;
queue<int> fire_h;

int hei, wid, s_w, s_h, f_w, f_h;
int f_map[MAX][MAX], time[MAX][MAX];

void clear(std::queue<int> &q) {
	std::queue<int> empty;
	std::swap(q, empty);
}

int initialize() {
	for (int x = 0; x < hei; x++) {
		for (int y = 0; y < wid; y++) {
			f_map[x][y] = MAX;
			time[x][y] = MAX;
		}
	}
	return 0;
}

int fire_map() {

	while (!fire_w.empty()) {
		f_w = fire_w.front();	fire_w.pop();		f_h = fire_h.front();	fire_h.pop();

		if ((map[f_h - 1][f_w] != '#') && (f_h - 1 >= 0) && (f_map[f_h - 1][f_w] > f_map[f_h][f_w])) {
			f_map[f_h - 1][f_w] = f_map[f_h][f_w] + 1;
			fire_h.push(f_h - 1);	fire_w.push(f_w);
		}
		if ((map[f_h][f_w - 1] != '#') && (f_w - 1 >= 0) && (f_map[f_h][f_w - 1] > f_map[f_h][f_w])) {
			f_map[f_h][f_w - 1] = f_map[f_h][f_w] + 1;
			fire_h.push(f_h);	fire_w.push(f_w - 1);
		}
		if ((map[f_h + 1][f_w] != '#') && (f_h + 1 < hei) && (f_map[f_h + 1][f_w] > f_map[f_h][f_w])) {
			f_map[f_h + 1][f_w] = f_map[f_h][f_w] + 1;
			fire_h.push(f_h + 1);	fire_w.push(f_w);
		}
		if ((map[f_h][f_w + 1] != '#') && (f_w + 1 < wid) && (f_map[f_h][f_w + 1] > f_map[f_h][f_w])) {
			f_map[f_h][f_w + 1] = f_map[f_h][f_w] + 1;
			fire_h.push(f_h);	fire_w.push(f_w + 1);
		}
	}

	/*for (int x = 0; x < hei; x++){
		printf("\n");
		for (int y = 0; y < wid; y++){
			printf("%d ", f_map[x][y]);
		}
	}*/
	return 0;
}

int BFS()
{
	sang_w.push(s_w);	sang_h.push(s_h);
	time[s_h][s_w] = 1;

	while (!sang_w.empty()) {
		s_w = sang_w.front();	sang_w.pop();		s_h = sang_h.front();	sang_h.pop();
		//printf("\n%d %d, %d %d\n", s_h, s_w, f_h, f_w);

		if ((s_w == 0) || (s_w == wid - 1) || (s_h == 0) || (s_h == hei - 1)) {
			printf("%d", time[s_h][s_w]);
			return 0;
		}

		if (map[s_h][s_w] == '*') {}
		else {
			if ((map[s_h - 1][s_w] == '.') && (s_h - 1 >= 0) && (time[s_h - 1][s_w] > time[s_h][s_w]) && (f_map[s_h - 1][s_w] > time[s_h][s_w])) {
				sang_h.push(s_h - 1);	sang_w.push(s_w);
				time[s_h - 1][s_w] = time[s_h][s_w] + 1;
			}
			if ((map[s_h][s_w - 1] == '.') && (s_w - 1 >= 0) && (time[s_h][s_w - 1] > time[s_h][s_w]) && (f_map[s_h][s_w - 1] > time[s_h][s_w])) {
				sang_h.push(s_h);		sang_w.push(s_w - 1);
				time[s_h][s_w - 1] = time[s_h][s_w] + 1;
			}
			if ((map[s_h + 1][s_w] == '.') && (s_h + 1 < hei) && (time[s_h + 1][s_w] > time[s_h][s_w]) && (f_map[s_h + 1][s_w] > time[s_h][s_w])) {
				sang_h.push(s_h + 1);	sang_w.push(s_w);
				time[s_h + 1][s_w] = time[s_h][s_w] + 1;
			}
			if ((map[s_h][s_w + 1] == '.') && (s_w + 1 < wid) && (time[s_h][s_w + 1] > time[s_h][s_w]) && (f_map[s_h][s_w + 1] > time[s_h][s_w])) {
				sang_h.push(s_h);		sang_w.push(s_w + 1);
				time[s_h][s_w + 1] = time[s_h][s_w] + 1;
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
