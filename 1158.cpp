#include<iostream>
#define len 5001

int N, K, cur, num;
int map[len];

int main() {
	scanf("%d %d", &N, &K);
	num = N;

	for (int t = 0; t <= N; t++) map[t] = t;

	printf("<");

	while (num != 0) {
		for (int t = 0; t < K; t++) {
			cur++;

			if (cur > N)
				cur = 0;

			if (map[cur] == 0)	
				t--;
		}

		printf("%d", map[cur]);	map[cur] = 0;
		num--;
		if (num > 0) printf(", ");
	}

	printf(">");

	return 0;
}
