#include <cstdio>
#define max 1000000

int N, people[max];
int guide_1, guide_2;
long long total;

int find_number() {
	total += N;

	int temp;

	for (int t = 0; t < N; t++) {
		if (people[t] > guide_1) {
			temp = (people[t] - guide_1) / guide_2;
			total += temp;

			if (temp * guide_2 < (people[t] - guide_1)) total++;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &N);

	for (int t = 0; t < N; t++) {
		scanf("%d", &people[t]);
	}

	scanf("%d", &guide_1);	scanf("%d", &guide_2);

	find_number();

	printf("%lld", total);

	return 0;
}
