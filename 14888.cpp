#include <iostream>

int N, max = -1000000000, min = 1000000000, ans;
int number[11], oper[10];
int already_calcul[10];

int operation() {
	ans = number[0];
	for (int x = 0; x < N-1; x++) {
		if (oper[already_calcul[x]] == 0) ans += number[x + 1];
		else if (oper[already_calcul[x]] == 1) ans -= number[x + 1];
		else if (oper[already_calcul[x]] == 2) ans = ans * number[x + 1];
		else ans = ans / number[x + 1];
	}

	return ans;
}

int calcul(int num) {

	if (num == (N-1)) {
		int temp = operation();
		max = (max > temp) ? max : temp;
		min = (min < temp) ? min : temp;
	}

	for (int x = 0; x < N - 1; x++) {
		int check = 0;
		for (int t = 0; t < num; t++) {
			if (already_calcul[t] == x)	{
				check = 1;
				break;
			}
		}
		if (check == 0) {
			already_calcul[num] = x;
			calcul(num + 1);
		}
	}

	return 0;
}

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



	calcul(0);

	printf("%d\n%d", max, min);

	return 0;
}
