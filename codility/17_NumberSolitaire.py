def solution(A):
    N = len(A)
    dp = [A[0]] * (N+6)
    
    for n in range(1, N):
        dp[n+6] = max(dp[n:n+6]) + A[n]
        
    return dp[-1]
