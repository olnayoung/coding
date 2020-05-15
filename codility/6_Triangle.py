def solution(A):
    A.sort()
    
    for n in range(len(A)-2):
        if A[n] + A[n+1] > A[n+2]:
            if A[n] + A[n+2] > A[n+1]:
                if A[n+1] + A[n+2] > A[n]:
                    return 1
                    
    return 0
