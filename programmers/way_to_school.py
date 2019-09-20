def solution(m, n, puddles):
    answer = 0
    ways = [[0]*(m+1) for _ in range (n+1)]
    
    for t in range (len(puddles)):
        ways[puddles[t][1]][puddles[t][0]] = 'x'
        
    for y in range (1, n+1):
        if ways[y][1] == 'x':
            continue
        ways[y][1] = 1
    for x in range (1, m+1):
        if ways[1][x] == 'x':
            continue
        ways[1][x] = 1
    
    for y in range (1, n+1):
        for x in range(1, m+1):
            if y == 1 and x == 1:
                continue
            if ways[y][x-1] == 'x':
                a = 0
            else:
                a = ways[y][x-1]
                
            if ways[y-1][x] == 'x':
                b = 0
            else:
                b = ways[y-1][x]
                
            if ways[y][x] == 'x':
                continue
            else:
                ways[y][x] = (a + b) % 1000000007
    
    answer = ways[n][m]
            
    return answer
