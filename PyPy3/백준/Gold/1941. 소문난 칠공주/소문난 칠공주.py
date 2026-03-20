import sys
from itertools import combinations
from collections import deque
input = sys.stdin.readline

seats = [[i for i in (input().rstrip())] for _ in range(5)]

line = [i for i in range(25)]
answer = 0
for combs in combinations(line, 7):
    selected = set((l // 5, l % 5) for l in combs)
    s_cnt = sum(1 for (x, y) in selected if seats[x][y] == 'S')
    
    if s_cnt >= 4:
        x = combs[0] // 5
        y = combs[0] % 5
        
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        
        q = deque([(x, y)])
        visited = set([(x, y)])
        while q:
            cx, cy = q.popleft()
            
            for i in range(4):
                nx, ny = cx + dx[i], cy + dy[i]
                
                if (nx, ny) in selected and (nx, ny) not in visited:
                    visited.add((nx, ny))
                    q.append((nx, ny))
        
        if len(visited) == 7: answer += 1

print(answer)