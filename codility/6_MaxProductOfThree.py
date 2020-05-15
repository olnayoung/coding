def solution(A):
    A.sort()
    
    N = len(A)
    mul = []
    a, b, c, d, e, f = A[0], A[1], A[2], A[N-3], A[N-2], A[N-1]
    
    mul.append(a*b*c)
    mul.append(a*b*f)
    mul.append(a*e*f)
    mul.append(d*e*f)
    
    return max(mul)
