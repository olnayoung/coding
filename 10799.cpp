#include<iostream>

int total, num, check, save_num;
char temp, b_temp;

int main() {
	while (1) {
		b_temp = temp;
		scanf("%1c", &temp);

		if (temp == '(') {
			num++;
		}
		else if (temp == ')') {
			if (b_temp == '(') {
				num--;
				total += num;
			}
			else {
				num--;
				total++;
			}
		}
		else if (temp == '\n')	break;
	}

	printf("%d", total);

	return 0;
}
