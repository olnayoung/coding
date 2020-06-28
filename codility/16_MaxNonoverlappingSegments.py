def solution(A, B):
    if len(A) == 0:
        return 0
        
    ans = 1
    END = B[0]
    
    
    for n in range(1, len(A)):
        if A[n] > END:
            ans += 1
            END = B[n]
            
    return ans
