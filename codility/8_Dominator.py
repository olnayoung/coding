def solution(A):
    check = {}
    position = {}
    
    for n in range(len(A)):
        if A[n] in check.keys():
            check[A[n]] += 1
        else:
            check[A[n]] = 1
            position[A[n]] = n
    
    if not check:
        return -1
    max_value = max(check.values())
    if max_value <= int(len(A)/2):
        return -1
        
    key_list = list(check.keys())
    for n in range(len(check)):
        if check[key_list[n]] == max_value:
            maxi = key_list[n]
            break
        
    return position[maxi]
