#include<iostream>
using namespace std;

int N, count_[1000001], check, max_count;
long long num[1000001], temp, numbers, max_num;

int main() {
	scanf("%d", &N);

	for (int t = 0; t < N; t++) {
		cin >> temp;

		for (int n = 0; n < numbers; n++) {
			if (num[n] == temp) {
				count_[n]++;
				check = 1;
				break;
			}
		}

		if (check == 0) {
			num[numbers] = temp;
			count_[numbers] = 1;
			numbers++;
		}
		else if (check == 1)	check = 0;
	}

	for (int t = 0; t < N; t++) {
		if (max_count < count_[t]) {
			max_count = count_[t];
			max_num = num[t];
		}
		else if (max_count == count_[t]) {
			max_num = (max_num < num[t]) ? max_num : num[t];
		}
	}

	printf("%lld", max_num);

	return 0;
}
