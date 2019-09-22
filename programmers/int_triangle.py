def solution(triangle):
    answer = 0
    
    for y in range(1, len(triangle)):
        triangle[y][0] += triangle[y-1][0]
        triangle[y][y] += triangle[y-1][y-1]
        
    for y in range(1, len(triangle)):
        for x in range(1, y):
            triangle[y][x] += max(triangle[y-1][x-1], triangle[y-1][x])
            
    answer = max(triangle[len(triangle)-1])
            
    return answer
