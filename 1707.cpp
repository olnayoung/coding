#include <iostream>
#include <vector>
#include <queue>
#define len 20001

using namespace std;

int K, V, E, a, b, check;
vector<int> graph[len];
queue<int>	que;
int color[len], visit[len];

int BFS(int n) {
	que.push(n);

	int a;
	while (que.size() != 0) {
		a = que.front();	que.pop();	visit[a] = 1;
		for (int t = 0; t < graph[a].size(); t++) {
			if (visit[graph[a][t]] == 0) {
				if (color[graph[a][t]] == color[a])	return 1;
				else {

					color[graph[a][t]] = 3 - color[a];
					if (visit[graph[a][t]] == 0) {
						que.push(graph[a][t]);
					}
				}
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d", &K);

	for (int k = 0; k < K; k++) {
		scanf("%d %d", &V, &E);

		for (int e = 0; e < E; e++) {
			scanf("%d %d", &a, &b);

			graph[a].push_back(b);	graph[b].push_back(a);
		}

		check = 0;
		for (int v = 1; v <= V; v++) {
			if (color[v] == 0) {
				color[v] = 1;
				if (BFS(v) == 1) {
					check = 1;
					printf("NO\n");
					break;
				}
			}
		}

		if (check == 0)	printf("YES\n");

		for (int v = 1; v <= V; v++) {
			graph[v].clear();
			color[v] = 0;
			visit[v] = 0;
		}

		while (!que.empty()) que.pop();

	}

	return 0;
}
