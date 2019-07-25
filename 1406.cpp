#include<iostream>
#define len 600001

int num_L, num_R, N;
char word_L[len], word_R[len], temp;

int main() {
	while (1) {
		scanf("%1c", &temp);

		if (temp == '\n')	break;
		word_L[num_L] = temp;
		num_L++;
	}

	scanf("%d", &N);

	for (int t = 0; t < N; t++) {
		getchar();
		scanf("%1c", &temp);

		if (temp == 'L') {
			if (num_L == 0)	continue;
			word_R[num_R] = word_L[num_L - 1];
			num_L--;	num_R++;
		}
		else if (temp == 'D') {
			if (num_R == 0) continue;
			word_L[num_L] = word_R[num_R - 1];
			num_L++;	num_R--;
		}
		else if (temp == 'B') {
			if (num_L == 0)	continue;
			num_L--;
		}
		else {
			getchar();
			scanf("%1c", &temp);
			word_L[num_L] = temp;
			num_L++;
		}
	}

	for (int t = 0; t < num_L; t++) printf("%1c", word_L[t]);
	for (int t = num_R - 1; t > -1; t--) printf("%1c", word_R[t]);

	return 0;
}
