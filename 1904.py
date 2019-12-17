dp = [0 for _ in range(1000000)]
dp[0] = 1
dp[1] = 2
N = int(input())

for n in range(2, N):
    dp[n] = (dp[n-1] + dp[n-2]) % 15746

print(dp[N-1])
