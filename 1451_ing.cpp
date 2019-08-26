#include <iostream>
#define len 101

int H, W, sq[len][len], S1, S2, S3;
long long ans;

long long max(long long a, long long b) {
	return (a > b) ? a : b;
}

int sum(int y1, int x1, int y2, int x2) {
	int out = 0;

	for (int y = y1; y < y2; y++)
		for (int x = x1; x < x2; x++)
			out += sq[y][x];

	return out;
}

int case1() {
	S1 = sum(0, 0, 1, W);
	S2 = sum(1, 0, H, 1);
	S3 = sum(1, 1, H, W);

	ans = max(ans, S1 * S2 * S3);

	for (int mid_y = 1; mid_y < H - 1; mid_y++) {

		for (int mid_x = 1; mid_x < W - 1; mid_x++) {
			for (int y = mid_y; y < H; y++) {
				for (int x = mid_x; x < W; x++) {
					S2 -= sq[y][x];
					S3 += sq[y][x];
				}
				ans = max(ans, S1 * S2 * S3);
			}

		}
	}


	return 0;
}

int main() {
	scanf("%d %d", &H, &W);

	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			scanf("%1d", &sq[y][x]);

	printf("%lld", ans);

	return 0;
}
