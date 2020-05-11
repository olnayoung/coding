def solution(A):
    N = len(A)
    mini = 500000
    minIdx = 0
    
    for n in range(N):
        if n+1 < N:
            if mini > (A[n] + A[n+1])/2:
                mini = (A[n] + A[n+1])/2
                minIdx = n
        
        if n+2 < N:
            if mini > (A[n] + A[n+1] + A[n+2])/3:
                mini = (A[n] + A[n+1] + A[n+2])/3
                minIdx = n
                
    return minIdx
