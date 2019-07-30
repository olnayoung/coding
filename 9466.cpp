#include <iostream>
#define len 100001

int K, N, temp;
int student[len], check[len], visit[len], ans[len], total;

int DFS(int a) {
	if (visit[a])	return a;
	if (check[a])	return 0;

	visit[a] = 1;	check[a] = 1;

	int next = DFS(student[a]);

	visit[a] = 0;

	if (next > 0) {
		ans[a] = 1;
		if (next != a)	return next;
	}

	return 0;
}

int main() {
	scanf("%d", &K);

	for (int k = 0; k < K; k++) {
		scanf("%d", &N);

		for (int n = 1; n < N + 1; n++) {
			scanf("%d", &temp);
			student[n] = temp;
		}

		for (int n = 1; n < N + 1; n++) {
			if (check[n] == 0) DFS(n);
		}

		for (int n = 1; n < N + 1; n++) {
			if (ans[n] == 0)	total++;
		}

		printf("%d\n", total);

		for (int n = 1; n < N + 1; n++) {
			student[n] = 0;
			visit[n] = 0;	check[n] = 0;		ans[n] = 0;
		}
	}

	return 0;
}
