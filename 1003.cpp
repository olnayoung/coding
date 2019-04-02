#include <iostream>
#define MAX 40
using namespace std;

int number[MAX];

int main()
{
	int iter, num;

	scanf("%d", &iter);

	number[0] = 0;
	number[1] = 1;

	for (int x = 2; x < 41; x++) {
		number[x] = number[x - 1] + number[x - 2];
	}

	for (int x = 0; x < iter; x++) {
		scanf("%d", &num);

		if (num == 0) {
			printf("1 0\n");
		}
		else {
			printf("%d %d\n", number[num - 1], number[num]);
		}
	}

	return 0;
}
