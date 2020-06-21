def solution(A):
    A = [abs(a) for a in A]
    A = list(set(A))
    
    return len(A)
