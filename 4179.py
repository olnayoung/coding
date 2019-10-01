dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
temp = input()
[R, C] = temp.split()
R = int(R)
C = int(C)

def BFS(S, maze):
    visit = [[R*C]*C for _ in range(R)]
    q = []
    for x in range(len(S)):
        q.append(S[x])
        visit[S[x][0]][S[x][1]] = 0

    while q:
        [y, x] = q.pop(0)

        for t in range(4):
            new_y = y + dy[t]
            new_x = x + dx[t]

            if new_y > -1 and new_y < R and new_x > -1 and new_x < C and maze[new_y][new_x] != '#':
                if visit[new_y][new_x] == (R*C):
                    visit[new_y][new_x] = visit[y][x] + 1
                    q.append([new_y, new_x])

    return visit

def main():
    maze = []
    Fs = []
    Js = []
    
    for y in range(R):
        temp = input()
        maze.append(temp)
        if 'J' in temp:
            Js.append([y, temp.index('J')])
        
        for x in range(C):
            if 'F' == temp[x]:
                Fs.append([y, x])
    JMap = BFS(Js, maze)
    FMap = BFS(Fs, maze)

    answer = R*C
    for x in range(C):
        if JMap[0][x] < FMap[0][x]:
            answer = min(answer, JMap[0][x])
        if JMap[R-1][x] < FMap[R-1][x]:
            answer = min(answer, JMap[R-1][x])

    for y in range(R):
        if JMap[y][0] < FMap[y][0]:
            answer = min(answer, JMap[y][0])
        if JMap[y][C-1] < FMap[y][C-1]:
            answer = min(answer, JMap[y][C-1])

    if answer == R*C:
        print('IMPOSSIBLE')
    else:
        print(answer + 1)

if __name__ == "__main__":
    main()
