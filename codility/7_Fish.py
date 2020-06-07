def solution(A, B):
    down = []
    up = 0
    
    for n in range(len(B)):
        if B[n] == 1:
            down.append(A[n])
        else:
            up += 1
            
            for m in range(len(down)-1, -1, -1):
                if A[n] < down[m]:
                    up -= 1
                    break
                else:
                    down.pop()
                    
                    
    return up + len(down)
