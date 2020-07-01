def solution(clothes):
    myDict = {}
    for name, c_type in clothes:
        if c_type in myDict.keys():
            myDict[c_type].append(name)
        else:
            myDict[c_type] = [name]
        
    answer = 1
    keyList = list(myDict.keys())
    for n in range(len(keyList)):
        answer = answer * (len(myDict[keyList[n]])+1)
        
    return answer-1
