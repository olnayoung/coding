def solution(weight):
    answer = 1

    weight.sort()

    for x in range(len(weight)):
        if answer < weight[x]:
            break
        answer += weight[x]

    return answer
