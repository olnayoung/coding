def solution(A, K):
    if not A:
        return []
    K %= len(A)
    new_array = A[len(A)-K:]
    new_array.extend(A[0:len(A)-K])
    
    return new_array
