long long gcd(long long a, long long b) {
	long long c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int lcm(int a, b)
{
    return a * b / gcd(a, b);
}
