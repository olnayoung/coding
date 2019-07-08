#include<iostream>

int N, M, cur, time;
int map[1000], dice[1000];

int move() {
	while (1) {
		cur += dice[time];
		time++;
		if (cur >= N - 1)	break;

		cur += map[cur];
		if (cur >= N - 1)	break;
	}

	return 0;
}

int main(){
	scanf("%d %d", &N, &M);

	for (int t = 0; t < N; t++) 
		scanf("%d", &map[t]);
	for (int t = 0; t < M; t++) 
		scanf("%d", &dice[t]);

	move();

	printf("%d", time);

	return 0;
}
