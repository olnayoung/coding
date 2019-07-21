#include<iostream>
#define max 10001
using namespace std;

int N, temp;
int map[max];

int main() {
	scanf("%d", &N);

	for (int y = 0; y < N; y++) {
		scanf("%d", &temp);
		map[temp]++;
	}

	for (int t = 0; t < max; t++) {
		if (map[t] != 0) {
			for (int a = 0; a < map[t]; a++) {
				printf("%d\n", t);
			}
		}
	}

	return 0;
}
