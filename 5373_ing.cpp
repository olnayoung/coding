#include <iostream>

int M, N;
char map[1001][2];
char up[3][3], down[3][3], left[3][3], right[3][3], front[3][3], back[3][3];

int clear() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			up[y][x] = 'w';	down[y][x] = 'y';	left[y][x] = 'g';	right[y][x] = 'b';	front[y][x] = 'r';	back[y][x] = 'o';
		}
	}
	return 0;
}

int spin_up(int n) {
	if (map[n][1] == '+') {
		for (int t = 0; t < 3; t++) {
			char temp = back[0][t];
			back[0][t] = left[0][t];
			left[0][t] = front[0][t];
			front[0][t] = right[0][t];
			right[0][t] = temp;
		}

		char temp = up[0][0];
		up[0][0] = up[2][0];	up[2][0] = up[2][2];	up[2][2] = up[0][2];	up[0][2] = temp;
		temp = up[0][1];
		up[0][1] = up[1][0];	up[1][0] = up[2][1];	up[2][1] = up[1][2];	up[1][2] = temp;
	}
	else {
		for (int t = 0; t < 3; t++) {
			char temp = right[0][t];
			right[0][t] = front[0][t];
			front[0][t] = left[0][t];
			left[0][t] = back[0][t];
			back[0][t] = temp;
		}

		char temp = up[0][0];
		up[0][0] = up[0][2];	up[0][2] = up[2][2];	up[2][2] = up[2][0];	up[2][0] = temp;
		temp = up[0][1];
		up[0][1] = up[1][2];	up[1][2] = up[2][1];	up[2][1] = up[1][0];	up[1][0] = temp;
	}
	return 0;
}

int spin_right(int n) {
	if (map[n][1] == '+') {
		for (int t = 0; t < 3; t++) {
			char temp = front[t][2];
			front[t][2] = down[2 - t][2];
			down[2 - t][2] = back[2 - t][0];
			back[2 - t][0] = up[t][2];
			up[t][2] = temp;
		}

		char temp = right[0][0];
		right[0][0] = right[2][0];	right[2][0] = right[2][2];	right[2][2] = right[0][2];	right[0][2] = temp;
		temp = right[0][1];
		right[0][1] = right[1][0];	right[1][0] = right[2][1];	right[2][1] = right[1][2];	right[1][2] = temp;
	}
	else {
		for (int t = 0; t < 3; t++) {
			char temp = front[t][2];
			front[t][2] = up[t][2];
			up[t][2] = back[2 - t][0];
			back[2 - t][0] = down[2 - t][2];
			down[2 - t][2] = temp;
		}

		char temp = right[0][0];
		right[0][0] = right[0][2];	right[0][2] = right[2][2];	right[2][2] = right[2][0];	right[2][0] = temp;
		temp = right[0][1];
		right[0][1] = right[1][2];	right[1][2] = right[2][1];	right[2][1] = right[1][0];	right[1][0] = temp;
	}
	return 0;
}

int spin_left(int n) {
	if (map[n][1] == '+') {
		for (int t = 0; t < 3; t++) {
			char temp = down[2 - t][0];
			down[2 - t][0] = front[t][0];
			front[t][0] = up[t][0];
			up[t][0] = back[2 - t][2];
			back[2 - t][2] = temp;
		}

		char temp = left[0][0];
		left[0][0] = left[2][0];	left[2][0] = left[2][2];	left[2][2] = left[0][2];	left[0][2] = temp;
		temp = left[0][1];
		left[0][1] = left[1][0];	left[1][0] = left[2][1];	left[2][1] = left[1][2];	left[1][2] = temp;
	}
	else {
		for (int t = 0; t < 3; t++) {
			char temp = up[t][0];
			up[t][0] = front[t][0];
			front[t][0] = down[2 - t][0];
			down[2 - t][0] = back[2 - t][2];
			back[2 - t][2] = temp;
		}

		char temp = left[0][0];
		left[0][0] = left[0][2];	left[0][2] = left[2][2];	left[2][2] = left[2][0];	left[2][0] = temp;
		temp = left[0][1];
		left[0][1] = left[1][2];	left[1][2] = left[2][1];	left[2][1] = left[1][0];	left[1][0] = temp;
	}
	return 0;
}

int spin_front(int n) {
	if (map[n][1] == '+') {
		for (int t = 0; t < 3; t++) {
			char temp = down[2][2 - t];
			down[2][2 - t] = right[t][0];
			right[t][0] = up[2][t];
			up[2][t] = left[2 - t][2];
			left[2 - t][2] = temp;
		}

		char temp = front[0][0];
		front[0][0] = front[2][0];	front[2][0] = front[2][2];	front[2][2] = front[0][2];	front[0][2] = temp;
		temp = front[0][1];
		front[0][1] = front[1][0];	front[1][0] = front[2][1];	front[2][1] = front[1][2];	front[1][2] = temp;
	}
	else {
		for (int t = 0; t < 3; t++) {
			char temp = up[2][t];
			up[2][t] = right[t][0];
			right[t][0] = down[2][2 - t];
			down[2][2 - t] = left[2 - t][2];
			left[2 - t][2] = temp;
		}

		char temp = front[0][0];
		front[0][0] = front[0][2];	front[0][2] = front[2][2];	front[2][2] = front[2][0];	front[2][0] = temp;
		temp = front[0][1];
		front[0][1] = front[1][2];	front[1][2] = front[2][1];	front[2][1] = front[1][0];	front[1][0] = temp;
	}
	return 0;
}

int spin_back(int n) {
	if (map[n][1] == '+') {
		for (int t = 0; t < 3; t++) {
			char temp = up[0][t];
			up[0][t] = right[t][2];
			right[t][2] = down[0][2 - t];
			down[0][2 - t] = left[2 - t][0];
			left[2 - t][0] = up[0][t];
		}

		char temp = back[0][0];
		back[0][0] = back[2][0];	back[2][0] = back[2][2];	back[2][2] = back[0][2];	back[0][2] = temp;
		temp = back[0][1];
		back[0][1] = back[1][0];	back[1][0] = back[2][1];	back[2][1] = back[1][2];	back[1][2] = temp;
	}
	else {
		for (int t = 0; t < 3; t++) {
			char temp = down[0][2 - t];
			down[0][2 - t] = right[t][2];
			right[t][2] = up[0][t];
			up[0][t] = left[2 - t][0];
			left[2 - t][0] = temp;
		}

		char temp = back[0][0];
		back[0][0] = back[0][2];	back[0][2] = back[2][2];	back[2][2] = back[2][0];	back[2][0] = temp;
		temp = back[0][1];
		back[0][1] = back[1][2];	back[1][2] = back[2][1];	back[2][1] = back[1][0];	back[1][0] = temp;
	}
	return 0;
}

int spin_down(int n) {
	if (map[n][1] == '+') {
		for (int t = 0; t < 3; t++) {
			char temp = left[2][t];
			left[2][t] = back[2][t]; 
			back[2][t] = right[2][t];
			right[2][t] = front[2][t];
			front[2][t] = temp;
		}

		char temp = down[0][0];
		down[0][0] = down[0][2];	down[0][2] = down[2][2];	down[2][2] = down[2][0];	down[2][0] = temp;
		temp = down[0][1];
		down[0][1] = down[1][2];	down[1][2] = down[2][1];	down[2][1] = down[1][0];	down[1][0] = temp;
	}
	else {
		for (int t = 0; t < 3; t++) {
			char temp = right[2][t];
			right[2][t] = back[2][t];
			back[2][t] = left[2][t];
			left[2][t] = front[2][t];
			front[2][t] = temp;
		}

		char temp = down[0][0];
		down[0][0] = down[2][0];	down[2][0] = down[2][2];	down[2][2] = down[0][2];	down[0][2] = temp;
		temp = down[0][1];
		down[0][1] = down[1][0];	down[1][0] = down[2][1];	down[2][1] = down[1][2];	down[1][2] = temp;
	}
	return 0;
}

int spin() {
	for (int t = 0; t < N; t++) {
		if (map[t][0] == 'U')	spin_up(t);
		else if (map[t][0] == 'R')	spin_right(t);
		else if (map[t][0] == 'L')	spin_left(t);
		else if (map[t][0] == 'F')	spin_front(t);
		else if (map[t][0] == 'B')	spin_back(t);
		else if (map[t][0] == 'D')	spin_down(t);
	}

	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			printf("%c", up[y][x]);
		}
		printf("\n");
	}
	return 0;
}

int main() {
	scanf("%d", &M);

	for (int m = 0; m < M; m++) {
		scanf("%d", &N);
		for (int n = 0; n < N; n++) {
			clear();
			char temp;
			scanf("%c", &temp);
			scanf("%c", &map[n][0]);
			scanf("%c", &map[n][1]);
		}
		spin();
	}

	return 0;
}
