def solution(A):
    check = [0]*1000001
    mini = 1

    for idx in range(len(A)):
        if A[idx] < 1:
            continue
        elif check[A[idx]] == 0:
            check[A[idx]] = 1
            if check[mini] == 1:
                while check[mini] == 1:
                    mini += 1

        elif check[A[idx]] == 1:
            continue

    return mini
