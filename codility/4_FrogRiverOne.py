def solution(X, A):
    if X == 0:
        return 0

    check = [0 for _ in range(max(max(A)+1, len(A)+1))]
    sums = 0

    for n in range(len(A)):
        if check[A[n]] != 1:
            sums += 1
            check[A[n]] = 1

            if sums == X:
                return n

    return -1
