N = int(input())
temp = input()
temp = temp.split()
mage = []
dp = [N for _ in range(N)]
check = 0

for x in range(len(temp)):
    mage.append(int(temp[x]))

dp[N-1] = 0
for n in range(N-2, -1, -1):
    if n + mage[n] >= (N - 1):
        check = 1
    if mage[n] > 0:
        for x in range(1, mage[n] + 1):
            if n + x < N:
                if mage[n + x] > 0:
                    dp[n] = min(dp[n], dp[n + x] + 1)
    else:
        dp[n] = 0

if check == 1:
    if dp[0] == 0 or dp[0] == N:
        print(-1)
    else:
        print(dp[0])
else:
    if N == 1:
        print(0)
    else:
        print(-1)

# print(dp)
