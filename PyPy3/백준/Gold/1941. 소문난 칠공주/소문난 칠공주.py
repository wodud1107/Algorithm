import sys
from itertools import combinations
from collections import deque
input = sys.stdin.readline

seats = [[i for i in (input().rstrip())] for _ in range(5)]

line = [i for i in range(25)]
answer = 0
for list in combinations(line, 7):
    members = []
    temp = [row[:] for row in seats]
    for l in list:
        x = l // 5
        y = l % 5
        members.append(seats[x][y])
        temp[x][y] = 'B'
    
    if members.count('S') >= 4:
        x = list[0] // 5
        y = list[0] % 5
        
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        
        q = deque([(x, y)])
        while q:
            cx, cy = q.popleft()
            
            for i in range(4):
                nx, ny = cx + dx[i], cy + dy[i]
                if not (0 <= nx < 5 and 0 <= ny < 5): continue
                if temp[nx][ny] != 'B': continue
                else:
                    temp[nx][ny] = 'O'
                    q.append((nx, ny))
        
        cnt = 0
        for i in range(5):
            for j in range(5):
                if temp[i][j] == 'B': cnt += 1
        if cnt == 0: answer += 1

print(answer)