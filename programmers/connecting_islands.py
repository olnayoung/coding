def solution(n, costs):
    answer = 0
    
    costs.sort()
    connect = [costs[0][0]]
    
    while len(connect) != n:
        temp = 99999999
        idx = 0
        for x in range(len(costs)):
            if costs[x][0] in connect or costs[x][1] in connect:
                if costs[x][0] in connect and costs[x][1] in connect:
                    continue
                if temp > costs[x][2]:
                    temp = costs[x][2]
                    idx = x
        
        answer += temp
        connect.append(costs[idx][0])
        connect.append(costs[idx][1])
        connect = list(set(connect))
        costs.pop(idx)
    
    return answer
