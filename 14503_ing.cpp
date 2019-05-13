#include <iostream>

int hei, wid;
int r, c, w;
int map[50][50];

int main() {
	scanf("%d %d", &hei, &wid);
	scanf("%d %d %d", &r, &c, &w);

	for (int y = 0; y < hei; y++) {
		for (int x = 0; x < wid; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	return 0;
}
