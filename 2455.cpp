#include<iostream>

int N, max, total;
int map[50][2];

int change() {
	for (int t = 0; t < 4; t++) { 
		total -= map[t][0];
		total += map[t][1];
		max = (max > total) ? max : total;
	}

	return 0;
}

int main(){
	for (int y = 0; y < 4; y++) {
		scanf("%d %d", &map[y][0], &map[y][1]);
	}

	change();

	printf("%d", max);

	return 0;
}
