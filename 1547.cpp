#include<iostream>

int N, ans = 1;
int map[50][2];

int change() {
	for (int t = 0; t < N; t++) {
		if ((map[t][0] == ans) || (map[t][1] == ans)) {
			if (map[t][0] == ans) ans = map[t][1];
			else ans = map[t][0];
		}
	}

	return 0;
}

int main(){
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		scanf("%d %d", &map[y][0], &map[y][1]);
	}

	change();

	printf("%d", ans);

	return 0;
}
