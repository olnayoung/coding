def solution(participant, completion):
    check_dict = {}
    check = [0]*len(participant)
    ans = ''
    
    for n in range(len(participant)):
        if participant[n] in check_dict.keys():
            check_dict[participant[n]].append(n)
        else:
            check_dict[participant[n]] = [n]
        
    for n in range(len(completion)):
        if len(check_dict[completion[n]]) == 1:
            check[check_dict[completion[n]][0]] = 1
        else:
            m = 0
            while check[check_dict[completion[n]][m]] == 1:
                m += 1
            check[ check_dict[completion[n]][m] ] = 1
    
    for n in range(len(check)):
        if check[n] == 0:
            for name, num in check_dict.items():
                if n in num:
                    return name
