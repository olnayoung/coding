def solution(N):
    max_gap = 0
    start_idx = 0
    end_idx = 0
    
    big = N
    while (big >= 1):
        remain = big % 2
        big = big // 2
        
        end_idx += 1
        if remain == 1:
            if start_idx != 0:
                max_gap = max(max_gap, end_idx - start_idx)
            
            start_idx = end_idx
        
    if max_gap != 0:
        max_gap -= 1
    
    return max_gap
