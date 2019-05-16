#include <iostream>

int r, c, k;
int map[100][100];

int main() {
	scanf("%d %d %d", &r, &c, &k);
	r--; c--;

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			scanf("%d", &map[y][x]);
		}
	}

	return 0;
}
