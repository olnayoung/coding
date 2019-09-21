import heapq

def solution(jobs):
    answer = 0
    total_time = 0
    start = -1
    N = len(jobs)
    ttt = max(jobs)
    M = ttt[0]
    q = []
    
    while start < max(M, N):
        temp = []
        for job in jobs:
            if start < job[0] <= total_time:
                heapq.heappush(q, [job[1], job[0]])
                temp.append([job[0], job[1]])
        for t in temp:
            jobs.remove([t[0], t[1]])
        if not q:
            total_time += 1
        else:
            [a, b] = heapq.heappop(q)
            answer += (total_time - b + a)
            total_time += a
        start += 1
        
    return answer // N
