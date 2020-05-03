def solution(N, A):
    ans = [0] * N
    maxi = 0
    check = 0

    for idx in range(len(A)):
        if A[idx] == N+1:
            if check == 0:
                ans = [maxi] * N
                check = 1
            else:
                continue
        else:
            check = 0
            ans[A[idx]-1] += 1
            maxi = max(maxi, ans[A[idx]-1])

    return ans
