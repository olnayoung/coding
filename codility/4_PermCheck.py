def solution(A):
    N = len(A)
    check = [0] * (N+2)
    mini = 1

    for idx in range(N):
        if A[idx] > N:
            return 0
        
        check[A[idx]] = 1

        while check[mini] == 1:
            mini += 1

    if mini == N+1:
        return 1
    else:
        return 0
