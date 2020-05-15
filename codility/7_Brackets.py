def solution(S):
    save = []
    opens = ['[', '(', '{']
    
    for n in range(len(S)):
        if S[n] in opens:
            save.append(S[n])
        else:
            if not save:
                return 0
                
            temp = save.pop()
            if temp == '[' and S[n] == ']':
                continue
            elif temp == '{' and S[n] == '}':
                continue
            elif temp == '(' and S[n] == ')':
                continue
            else:
                return 0
                
    if not save:
        return 1
    else:
        return 0
