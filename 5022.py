dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
N = 0
M = 0
A1 = []
A2 = []
B1 = []
B2 = []

def connect(A1, A2, record):
    line = []
    [x, y] = A2
    line.append([x, y])

    while [x, y] != A1:
        pre_x = x
        pre_y = y
        [x, y] = record[pre_x][pre_y]
        line.append([x, y])

    return line

def BFS1(con1, con2, discon1, discon2):
    q = [con1]
    record = [[0] * M for _ in range(N)]
    visit = [[N*M] * M for _ in range(N)]
    visit[con1[0]][con1[1]] = 0

    while q:
        [x, y] = q.pop(0)
        if [x, y] == con2:
            return record, visit[con2[0]][con2[1]]
        for t in range(4):
            new_y = y + dy[t]
            new_x = x + dx[t]
            if new_x >= 0 and new_x < N and new_y >= 0 and new_y < M and [new_x, new_y] != discon1 and [new_x, new_y] != discon2 and visit[new_x][new_y] == N*M:
                visit[new_x][new_y] = visit[x][y] + 1
                q.append([new_x, new_y])
                record[new_x][new_y] = [x, y]

    return 0, 'IMPOSSIBLE'

def BFS2(con1, con2, discon):
    q = [con1]
    record = [[0] * M for _ in range(N)]
    visit = [[N*M] * M for _ in range(N)]
    visit[con1[0]][con1[1]] = 0

    while q:
        [x, y] = q.pop(0)
        if [x, y] == con2:
            return visit[con2[0]][con2[1]]
        for t in range(4):
            new_y = y + dy[t]
            new_x = x + dx[t]
            if new_x >= 0 and new_x < N and new_y >= 0 and new_y < M and [new_x, new_y] not in discon and visit[new_x][new_y] == N*M:
                visit[new_x][new_y] = visit[x][y] + 1
                q.append([new_x, new_y])
                record[new_x][new_y] = [x, y]

    return 'IMPOSSIBLE'

def get_data():
    global N, M, A1, A2, B1, B2
    tmp = []
    for _ in range(5):
        temp = input()
        temp = temp.split()
        tmp.append([int(temp[0]), int(temp[1])])
    [N, M] = tmp[0]
    N += 1
    M += 1
    A1 = tmp[1]
    A2 = tmp[2]
    B1 = tmp[3]
    B2 = tmp[4]

def main():
    answer1 = 0
    answer2 = 0
    ans_pos1 = 1
    ans_pos2 = 1
    get_data()

    record, A = BFS1(A1, A2, B1, B2)
    if A == 'IMPOSSIBLE':
        ans_pos1 = 0
    else:
        answer1 += A
        line = connect(A1, A2, record)
        B = BFS2(B1, B2, line)
        if B == 'IMPOSSIBLE':
            ans_pos1 = 0
        else:
            answer1 += B

    record, B = BFS1(B1, B2, A1, A2)
    if B == 'IMPOSSIBLE':
        ans_pos2 = 0
    else:
        answer2 += B
        line = connect(B1, B2, record)
        A = BFS2(A1, A2, line)
        if A == 'IMPOSSIBLE':
            ans_pos2 = 0
        else:
            answer2 += A

    if ans_pos1 == 1 and ans_pos2 == 1:
        answer = min(answer1, answer2)
    elif ans_pos1 == 0 and ans_pos2 == 1:
        answer = answer2
    elif ans_pos1 == 1 and ans_pos2 == 0:
        answer = answer1
    else:
        answer = 'IMPOSSIBLE'
    print(answer)

    return 0

if __name__ == "__main__":
    main()
