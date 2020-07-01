def solution(answers):
    st1 = [1, 2, 3, 4, 5] * 2000
    st2 = [2, 1, 2, 3, 2, 4, 2, 5] * 1250
    st3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5] * 1000
    ans1, ans2, ans3 = 0, 0, 0
    
    for n in range(len(answers)):
        cur = answers[n]
        if cur == st1[n]:
            ans1 += 1
        if cur == st2[n]:
            ans2 += 1
        if cur == st3[n]:
            ans3 += 1
            
    maxi = max(ans1, ans2, ans3)
    answer = []
    if maxi == ans1:
        answer.append(1)
    if maxi == ans2:
        answer.append(2)
    if maxi == ans3:
        answer.append(3)
    
    return answer
