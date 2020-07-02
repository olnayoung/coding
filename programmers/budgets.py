def semiFinal(A, mid):
    sums = 0
    for n in range(len(A)):
        if A[n] > mid:
            sums += mid
        else:
            sums += A[n]
    return sums

def solution(budgets, M):
    budgets.sort()
    if sum(budgets) <= M:
        return budgets[-1]
    
    low = 0
    high = budgets[-1]
    
    while (low <= high):
        mid = int((low + high) / 2)
        print(low, mid, high)
        
        curSum = semiFinal(budgets, mid)
        if curSum > M:
            high = mid - 1
        elif curSum <= M:
            answer = mid
            low = mid + 1
    
    return answer
