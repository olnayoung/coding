#include<iostream>

int N, count, cur = 64;
int goal;

int change() {
	while (goal != 0) {
		if (goal < cur) {
			cur /= 2;
		}
		else {
			goal -= cur;
			count++;
		}
	}

	return 0;
}

int main(){
	scanf("%d", &goal);

	change();

	printf("%d", count);

	return 0;
}
