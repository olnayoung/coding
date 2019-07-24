#include<iostream>
#define len 10000

int N, K, start, finish;
char work[5];
int map[len];

int push (int k) {
	map[finish] = k;
	finish++;

	return 0;
}

int pop() {
	if (start < finish){
		printf("%d\n", map[finish - 1]);
		finish--;
	}
	else printf("-1\n");

	return 0;
}

int size() {
	printf("%d\n", finish - start);

	return 0;
}

int empty() {
	if (start == finish) printf("1\n");
	else printf("0\n");

	return 0;
}

int top() {
	if (start < finish){
		printf("%d\n", map[finish - 1]);
	}
	else printf("-1\n");
	return 0;
}

int main() {
	scanf("%d", &N);

	for (int t = 0; t < N; t++) {
		scanf("%s", &work);

		if ((work[0] == 'p') && (work[1] == 'u')) {
			scanf("%d", &K);
			push(K);
		}
		else if ((work[0] == 'p') && (work[1] == 'o')) pop();
		else if (work[0] == 's') size();
		else if (work[0] == 'e') empty();
		else if (work[0] == 't') top();
	}

	return 0;
}
