def solution(A):
    start = -1
    for n in range(len(A)):
        if A[n] == 0:
            start = n
            break
    
    if start == -1:
        return 0
        
    num = 0
    for idx in range(start+1, len(A)):
        if A[idx] == 1:
            num += 1
            
    sumi = num
    for idx in range(start+1, len(A)):
        if A[idx] == 1:
            num -= 1
        else:
            sumi += num
            
        if sumi > 1000000000:
            return -1
            
    return sumi
