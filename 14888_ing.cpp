#include <iostream>

int N, max = 0, min = 100000000;
int number[11], oper[10];

int main() {
	scanf("%d", &N);

	for (int x = 0; x < N; x++) {
		scanf("%d", &number[x]);
	}

	int temp = 0;

	for (int x = 0; x < 4; x++) {
		int temp2;
		scanf("%d", &temp2);

		temp2 += temp;

		for (int t = temp; t < temp2; t++) {
			oper[t] = x;
		}
		temp = temp2;
	}

	printf("%d\n%d", max, min);

	return 0;
}
