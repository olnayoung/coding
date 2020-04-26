def solution(A):
    min_diff = 100000000
    
    front_sum = A[0]
    end_sum = sum(A[1:])
    
    min_diff = min(min_diff, abs(front_sum-end_sum))
    
    for n in range(1, len(A)-1):
        front_sum += A[n]
        end_sum -= A[n]
        min_diff = min(min_diff, abs(front_sum-end_sum))
        
    return min_diff
