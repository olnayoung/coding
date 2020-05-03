def solution(A, B, K):
    ans = (B-A+1) // K
    b = (B-A+1) % K

    if (B-A+1) % K != 0:
        for n in range(A, min(A+b-1, B)+1):
            if n % K == 0:
                ans += 1
                break

    return ans
