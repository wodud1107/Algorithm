import sys
from collections import deque
input = sys.stdin.readline

N, M, T = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]

def bfs():
    q = deque([(0, 0)])
    visited = [[-1] * M for _ in range(N)]
    visited[0][0] = 0
    
    gram_dist = float('inf')
    
    while q:
        x, y = q.popleft()
        if board[x][y] == 2:
            gram_dist = visited[x][y] + (N - 1 - x) + (M - 1 - y)
            
        if x == N - 1 and y == M -1 :
            return min(visited[x][y], gram_dist)
        
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            
            if 0 <= nx < N and 0 <= ny < M and visited[nx][ny] == -1:
                if board[nx][ny] == 0 or board[nx][ny] == 2:
                    visited[nx][ny] = visited[x][y] + 1
                    q.append((nx, ny))
                    
    return gram_dist

spend_time = bfs()
if spend_time > T: print("Fail")
else: print(spend_time)