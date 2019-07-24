#include<iostream>

int N, num, check = 1;
char temp;

int main() {
	scanf("%d", &N);
	getchar();

	for (int t = 0; t < N; t++) {
		num = 0;
		check = 0;

		while (1) {
			scanf("%1c", &temp);

			if (temp == '(') num++;
			else if (temp == ')') {
				if (num == 0) check = -1;
				else num--;
			}
			else if (temp == '\n') break;
		}

		if ((num == 0) && (check == 0)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
