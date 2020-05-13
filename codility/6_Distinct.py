def solution(A):
    check = [0 for _ in range(2000005)]
    
    for n in range(len(A)):
        check[A[n]+1000000] = 1
    
    return sum(check)
