word = input()
vrs = input()

N = len(word)
M = len(vrs)
ans = []
an = 0
n = 0
m = 0

while n < N:
    # print(ans)
    if an >= len(ans):
        ans.append(word[n])
    else:
        ans[an] = word[n]

    if word[n] == vrs[M-1]:

        check = 0
        for m in range(M):
            if ans[an-m] != vrs[M-1-m]:
                check = 1
                break

        if check == 0:
            an -= (m+1)

    # print(n, an, ans)
    n += 1
    an += 1

ans = ''.join(ans)
if an > 0:
    print(ans[0:an])
else:
    print('FRULA')
