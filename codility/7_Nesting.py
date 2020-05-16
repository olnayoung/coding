def solution(S):
    check = []
    for n in range(len(S)):
        if S[n] == '(':
            check.append(S[n])
            
        else:
            if not check:
                return 0
            else:
                check.pop()
                
    if not check:
        return 1
    else:
        return 0
