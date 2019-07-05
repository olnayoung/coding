#include<iostream>
#define max(a, b) (a > b) ? a : b

int N, M, a;
int map[1001][1001];

int main(){
	scanf("%d %d", &N, &M);

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%d", &map[y][x]);
			a = max(map[y][x - 1], map[y - 1][x - 1]);
			map[y][x] += max(a, map[y - 1][x]);
		}
	}

	printf("%d", map[N][M]);

	return 0;
}
