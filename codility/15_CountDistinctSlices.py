def solution(M, A):
    appearance = [0] * (M + 1)
    N = len(A)
    front = 0 
    slices = 0
    
    for back in range(N):
        while front < N and appearance[A[front]] == 0:
            appearance[A[front]] += 1
            slices += front - back +1
            front += 1
        appearance[A[back]] -= 1
        
        if slices >= 1000000000:
            return 1000000000
        
    return slices
