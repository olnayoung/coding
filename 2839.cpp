#include <iostream>
using namespace std;

int N, q, remain;
int num_3, num_5;

int main() {
	scanf("%d", &N);

	if ((N == 4) || (N == 7)) {
		printf("-1");
		return 0;
	}

	q = N / 5;
	remain = N % 5;

	if (remain == 0) {
		num_3 = 0;
		num_5 = q;
	}
	else if (remain == 1) {
		num_3 = 2;
		num_5 = q-1;
	}
	else if (remain == 2) {
		num_3 = 4;
		num_5 = q-2;
	}
	else if (remain == 3) {
		num_3 = 1;
		num_5 = q;
	}
	else {
		num_3 = 3;
		num_5 = q-1;
	}

	printf("%d", num_3 + num_5);
}
