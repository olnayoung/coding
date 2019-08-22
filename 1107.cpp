#include <iostream>
#define len 5000001
int N, dest, no[10], cur = 100, min, output;
int remain;

int getDist(int number) {
	return (dest > number) ? dest - number : number - dest;
}

int Length(int number) {
	if (number == 0) return 1;

	output = 0;
	while (number) {
		number /= 10;
		output++;
	}

	return output;
}

int ifPossible(int number) {
	if (number == 0) {
		for (int n = 0; n < N; n++) {
			if (remain == no[n])	return 1;
		}
	}

	while (number) {
		remain = number % 10;
		for (int n = 0; n < N; n++) {
			if (remain == no[n])	return 1;
		}
		number /= 10;
	}

	return 0;
}

int tryAll() {
	for (int m = 0; m < len; m++) {
		if (!ifPossible(m)) {
			output = getDist(m) + Length(m);
			if (min > output) {
				int a = 1;
				a++;
			}
			min = (min < output) ? min : output;
		}
	}

	return 0;
}

int main() {
	scanf("%d", &dest);
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", &no[n]);
	}

	if (dest == cur) {
		printf("0");
		return 0;
	}

	min = getDist(cur);
	tryAll();

	printf("%d", min);

	return 0;
}
