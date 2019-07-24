#include<iostream>
#define len 600001

int cur, num, N;
char word[len], temp, save, save2, pos;

int main() {
	while (1) {
		scanf("%1c", &temp);

		if (temp == '\n')	break;
		word[num] = temp;	num++;
	}
	cur = num;

	scanf("%d", &N);

	for (int t = 0; t < N; t++) {
		getchar();
		scanf("%1c", &temp);

		if (temp == 'L') {
			while (1) {
				if (cur == 0) break;
				cur--;
				if (word[cur] != 0) break;
			}
		}
		else if (temp == 'D') {
			while (1) {
				if (word[cur - 1] != 0) break;
				cur++;
				if (word[cur - 1] != 0) break;
			}
		}
		else if (temp == 'B') {
			if (cur == 0)	continue;
			word[cur - 1] = 0;

			while (1) {
				if (cur == 0) break;
				cur--;
				if (word[cur - 1] != 0) break;
			}
		}
		else {
			getchar();
			scanf("%1c", &temp);
			num++;
			pos = cur;
			cur++;

			while (1) {
				if (word[pos] == 0) {
					word[pos] = temp;
					break;
				}
				else {
					save = word[pos];
					word[pos] = temp;
					temp = word[pos + 1];
					word[pos + 1] = save;
					pos+=2;
				}

			}
		}
	}

	for (int t = 0; t < num; t++) {
		if (word[t] != 0)	printf("%1c", word[t]);
	}

	return 0;
}
