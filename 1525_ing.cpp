#include<iostream>
#include<map>
#define max 999999
using namespace std;

int idx[4] = { 1, 3, -1, -3 };
int size, step, found;
int tmp[9], input, cur, node[9];
int que[max], start, finish;
map<int, int> visited;

int move() {
	que[finish] = input;	finish++;

	while ((start < finish) && !found){
		size = finish - start;

		for (int t = 0; t < size && !found; t++) {
			cur = que[start];	start++;

			for (int i = 8; i >= 0; i--) {
				tmp[i] = cur % 10;
				cur /= 10;

				if (tmp[i] == 0)	input = i;
			}

			for (int i = 0; i < 4; i++) {
				if (input + idx[i] < 0 || input + idx[i] > 8 || (input == 2 && i == 0) || (input == 3 && i == 2) || (input == 5 && i == 0) || (input == 6 && i == 2))
					continue;

				for (int j = 0; j < 9; j++)	node[j] = tmp[j];

				node[input] = node[input + idx[i]];
				node[input + idx[i]] = 0;
				cur = 0;

				for (int j = 0; j < 9; j++) {
					cur = cur * 10 + node[j];
				}

				if (cur == 123456780) {
					found = 1;
					break;
				}

				if (visited.find(cur) == visited.end()){
					visited[cur] = 1;
					que[finish] = cur;	finish++;
				}
			}
		}

		step++;
	}
	return 0;
}

int move() {
	q.push(input);

	while (!q.empty() && !found){

		size = q.size();

		for (int t = 0; t < size && !found; t++){
			curr = q.front();
			q.pop();

			for (int i = 8; i >= 0; i--){
				tmp[i] = curr % 10;
				curr /= 10;
				if (tmp[i] == 0){
					input = i;
				}
			}

			for (int i = 0; i<4; i++){
				if (input + idx[i] < 0 || input + idx[i] > 8 ||
					(input == 2 && i == 0) || (input == 3 && i == 2) || (input == 5 && i == 0) || (input == 6 && i == 2))
					continue; //범위를 넘어가거나 0부터 8번까지 자리를 둔다면 2번과 3번, 5번과 6번자리는 바꿀 수 없음

				for (int j = 0; j<9; j++)
					node[j] = tmp[j];

				node[input] = node[input + idx[i]];
				node[input + idx[i]] = 0;
				cur = 0;

				for (int j = 0; j<9; j++){
					cur = cur * 10 + node[j];
				}

				if (cur == 123456780){
					found = 1;
					break;
				}

				if (visited.find(cur) == visited.end()){
					visited[cur] = 1;
					q.push(cur);
				}
			}
		}

		step++;
	}
	return 0;
}

int main(){
	for (int i = 0; i<9; i++){
		scanf("%1d", &tmp[i]);
		input = input * 10 + tmp[i];
	}

	if (input == 123456780){
		printf("0");
		return 0;
	}

	move();

	if (!found)
		printf("-1\n");
	else
		printf("%d\n", step);

	return 0;
}
