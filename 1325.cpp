#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 10001

int com, line;
bool visit[MAX];
int total[MAX];
int max_count = 0;
vector < vector<int>> trust;

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int DPS(int start) {
	visit[start] = true;

	int ret = 0;
	for (int x = 0; x < (int)trust[start].size(); x++) {

		if (!visit[trust[start][x]]) {
			ret += DPS(trust[start][x]) + 1;
		}
	}

	return ret;
}

int main() {
	int from, to;
	scanf("%d %d", &com, &line);

	trust.resize(com+1);

	for (int x = 0; x < line; x++) {
		scanf("%d %d", &from, &to);
		trust[to].push_back(from);
	}

	for (int x = 0; x < com; x++) {
		total[x] = DPS(x+1);
		max_count = max(max_count, total[x]);

		memset(visit, 0, sizeof(visit));
	}

	for (int x = 0; x < com; x++) {
		if (total[x] == max_count) {
			printf("%d ", x+1);
		}
	}

	return 0;
}
