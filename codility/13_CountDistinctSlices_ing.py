def solution(M, A):
    ans = 0
    N = len(A)
    nums = [0] * (N+1)
    for n in range(1, N+1):
        nums[n] = nums[n-1] + n
        if nums[n] >= 1000000000:
            nums[n] = 1000000000
        
    check = [0] * (M+1)
    number = 0
    for n in range(N):
        if check[A[n]] == 0:
            check[A[n]] = 1
            number += 1
        else:
            check = [0] * (M+1)
            ans += nums[number]
            if ans > 1000000000:
                return 1000000000
                
            check[A[n]] = 1
            number = 1
            
    ans += nums[number]
    if ans > 1000000000:
        return 1000000000
            
    return ans
