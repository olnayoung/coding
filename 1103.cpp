#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 50

char map[MAX][MAX];
int visit[MAX][MAX];
int hei, wid, ans = 0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int num = 0;

int game(int y, int x) {
	if ((y < 0) && (x < 0) && (y >= hei) && (x >= wid))	return 0;
	if (map[y][x] == 'H')	return 0;
	if (visit[y][x] == 1) {
		printf("-1");
		exit(0);
	}
	int new_h, new_w;

	for (int t = 0; t < 4; t++) {
		new_h = y + dy[t] * map[y][x];		new_w = x + dx[t] * map[y][x];

		//printf("\n%d %d %d\n", map[y][x], new_h, new_w);
		visit[y][x] = 1;
		//num = 1 + game(new_h, new_w);
		num = max(num, 1 + game(new_h, new_w));
		visit[y][x] = 0;
	}

	return num;
}

int main()
{
	char tmp;
	scanf("%d %d", &hei, &wid);

	for (int y = 0; y < hei; y++) {
		for (int x = 0; x < wid; x++) {
			scanf(" %c", &tmp);
			if (tmp != 'H') map[y][x] = tmp - 48;
			else map[y][x] = tmp;
			visit[y][x] = 0;
		}
	}

	printf("%d", num);

	return 0;
}
