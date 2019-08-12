#include <iostream>
#define len 500001
using namespace std;

int N;
long long arr[len], arr2[len], result;

long long func(int start, int end) {
	if (start == end)
		return 0;

	int i, j, idx, mid;
	mid = (start + end) / 2;	i = start;	j = mid + 1;	idx = 0;

	result = func(start, mid) + func(mid + 1, end);

	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || arr[i] <= arr[j]))
			arr2[idx++] = arr[i++];
		else {
			result += (mid - i + 1);
			arr2[idx++] = arr[j++];
		}
	}

	for (int k = start; k <= end; k++)
		arr[k] = arr2[k - start];

	return result;
}

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++)
		scanf("%lld", &arr[n]);

	result = func(0, N - 1);

	printf("%lld", result);

	return 0;
}
