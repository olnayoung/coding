#include<iostream>
#include <vector>

using namespace std;

int N, K, cur = -1, num;

int main() {
	scanf("%d %d", &N, &K);
	num = N;

	vector<int> vc(N);

	for (int t = 0; t < N; t++) vc[t] = t + 1;

	printf("<");

	while (vc.size() != 0) {
		cur += K;

		if (cur >= vc.size())
			cur %= vc.size();

		printf("%d", vc[cur]);	vc.erase(vc.begin() + cur);
		cur--;

		if (vc.size() > 0) printf(", ");
	}

	printf(">");

	return 0;
}
