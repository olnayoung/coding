def solution(A):
    max_end = max_slice = 0
    for a in A:
        max_end = max(0, max_end + a)
        max_slice = max(max_slice, max_end)
    
    if max_slice == 0:
        max_slice = max(A)
    
    return max_slice
