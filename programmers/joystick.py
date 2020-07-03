def solution(name):
    N = len(name)
    
    notA = []
    for n in range(N):
        if name[n] != 'A':
            notA.append(n)
            mini = n
            
    if not notA:
        return 0
    
    notN = len(notA)
    for n in range(0, notN):
        temp = sum(notA[:n])*2 + (N - notA[n])
        if temp < mini:
            mini = temp
    
    answer = mini
    for n in range(N):
        if name[n] == 'N':
            answer += 13
        elif name[n] > 'N':
            answer += (ord('Z') - ord(name[n]) + 1)
        else:
            answer += (ord(name[n]) - ord('A'))
    
    return answer
