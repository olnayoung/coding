temp = input()
[a, b, c] = temp.split()
A = int(a)
B = int(b)
C = int(c)

q = [[0, 0, C]]
n = 0
answer = []

while n < len(q):
    [a, b, c] = q[n]
    # print(q[n])

    if a == 0:
        answer.append(c)

    if a + b > B:  # A -> B
        new_A = a - B + b
        new_B = B
    else:
        new_A = 0
        new_B = a + b
    new_C = c
    if [new_A, new_B, new_C] not in q:
        # print(1, [new_A, new_B, new_C])
        q.append([new_A, new_B, new_C])

    if a + c > C:  # A -> C
        new_A = a - C + c
        new_C = C
    else:
        new_A = 0
        new_C = a + c
    new_B = b
    if [new_A, new_B, new_C] not in q:
        # print(2, [new_A, new_B, new_C])
        q.append([new_A, new_B, new_C])

    if a + b > A: # B -> A
        new_A = A
        new_B = a - A + b
    else:
        new_A = a + b
        new_B = 0
    new_C = c
    if [new_A, new_B, new_C] not in q:
        # print(3, [new_A, new_B, new_C])
        q.append([new_A, new_B, new_C])

    if b + c > C: # B -> C
        new_B = b + c - C
        new_C = C
    else:
        new_B = 0
        new_C = b + c
    new_A = a
    if [new_A, new_B, new_C] not in q:
        # print(4, [new_A, new_B, new_C])
        q.append([new_A, new_B, new_C])

    if a + c > A: # C -> A
        new_A = A
        new_C = a + c - A
    else:
        new_A = a + c
        new_C = 0
    new_B = b
    if [new_A, new_B, new_C] not in q:
        # print(5, [new_A, new_B, new_C])
        q.append([new_A, new_B, new_C])

    if b + c > B: # C -> B
        new_B = B
        new_C = b + c - B
    else:
        new_B = b + c
        new_C = 0
    new_A = a
    if [new_A, new_B, new_C] not in q:
        # print(6, [new_A, new_B, new_C])
        q.append([new_A, new_B, new_C])

    n += 1

answer = list(set(answer))
answer.sort()

for x in range(len(answer)):
    print(answer[x], end=' ')
