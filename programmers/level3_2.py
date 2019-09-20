import queue
q = queue.Queue()

def BFS(gr, N):
    visit = [0 for _ in range(N)]
    dist = [N for _ in range(N)]
    answer = 0
    dist[0] = 0
    q.put(0)

    while (q.qsize() != 0):
        x = q.get()
        for t in range(len(gr[x])):
            if visit[gr[x][t]] == 0 and dist[x] + 1 < dist[gr[x][t]]:
                q.put(gr[x][t])
                visit[gr[x][t]] = 1
                dist[gr[x][t]] = dist[x] + 1

    dist.sort(reverse = True)

    for x in range(N):
        if dist[0] == dist[x]:
            answer+=1
        else:
            break

    return answer

def solution(n, edge):
    answer = 0
    N = len(edge)
    gr = [[] for _ in range(N)]

    for t in range(N):
        a = edge[t][1] - 1
        b = edge[t][0] - 1
        if not a in gr[b]:
            gr[b].append(a)
            gr[b].sort()
        if not b in gr[a]:
            gr[a].append(b)
            gr[b].sort()

    #print(gr)
   # for t in range(N):
    #    gr[edge[t][0] - 1][edge[t][1] - 1] = 1
    #    gr[edge[t][1] - 1][edge[t][0] - 1] = 1

    answer = BFS(gr, n)

    return answer
