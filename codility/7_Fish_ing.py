def solution(A, B):
    up = []
    down = []
    
    for n in range(len(A)):
        if B[n] == 0:
            if not down:
                up.append(A[n])
            else:
                cur = down.pop(0)
                
                while 1:
                    if cur > A[n]:
                        down.append(cur)
                        break
                    else:
                        if not down:
                            up.append(A[n])
                            break
                        else:
                            cur = down.pop(0)
        else:
            down.append(A[n])
    
    return len(up) + len(down)
