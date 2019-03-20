#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;
int visit[MAX];
queue<int> q;

void findBrother(int subin, int sis) {
	int curr = subin;
    
	visit[curr] = 1;
	q.push(curr);

	while (!q.empty()) {
		curr = q.front();
		q.pop();

		if (curr == sis) {
			cout << visit[curr] - 1 << "\n";
			break;
		}
		if (curr - 1 >= 0 && visit[curr - 1] == 0) {
			q.push(curr - 1);
			visit[curr - 1] = visit[curr] + 1;
		}
		if (curr + 1 <= 100000 && visit[curr + 1] == 0) {
			q.push(curr + 1);
			visit[curr + 1] = visit[curr] + 1;
		}
		if (curr * 2 <= 100000 && visit[curr * 2] == 0) {
			q.push(curr * 2);
			visit[curr * 2] = visit[curr] + 1;
		}
	}
}

int main() {
	int subin, sis;

	scanf("%d %d", &subin, &sis);
	findBrother(subin, sis);
}
