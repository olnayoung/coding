temp = input()
[N, M] = temp.split()
N = int(N)
M = int(M)
mat = [[0] * M for _ in range(N)]
maxi = 0

for n in range(N):
    temp = str(input())

    for m in range(M):
        mat[n][m] = int(temp[m])
        if mat[n][m] == 1:
            maxi = 1

for n in range(1, N):
    for m in range(1, M):
        if mat[n][m] == 1:
            mini = min(mat[n-1][m], mat[n][m-1], mat[n-1][m-1])

            if mini > 0:
                mat[n][m] = mini + 1
                maxi = max(mat[n][m], maxi)

print(maxi*maxi)
