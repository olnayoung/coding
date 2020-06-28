def solution(A, B):
    N = max(A)
    maxi = 2**30
    ans = []
    fib = [0] * (N+1)
    fib[0], fib[1] = 1, 1
    
    for n in range(2, N+1):
        fib[n] = (fib[n-1] + fib[n-2]) % maxi
        
    for n in range(len(A)):
        ans.append(fib[A[n]] % (2**B[n]))
        
    return ans
