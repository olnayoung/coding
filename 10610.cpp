#include <iostream>
#include <string>

using namespace std;

int N, sum, num[10];

int main() {
	string S;
	cin >> S;

	for (int n = 0; n < S.length(); n++) {
		N = S[n] - '0';
		num[N]++;
		sum += N;
	}

	if (num[0] == 0)	{
		printf("-1");
		return 0;
	}
	else if (sum % 3 != 0) {
		printf("-1");
		return 0;
	}

	for (int n = 9; n >= 0; n--) {
		for (int t = 0; t < num[n]; t++) {
			printf("%d", n);
		}
	}

	return 0;
}
