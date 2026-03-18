import sys
from collections import deque
input = sys.stdin.readline

def bfs(N, board):
    visited = [[float('inf')] * N for _ in range(N)]
    visited[0][0] = board[0][0]
    q = deque([(0, 0)])
    
    while q:
        x, y = q.popleft()
            
        for (dx, dy) in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            nx, ny = x + dx, y + dy
            
            if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] > visited[x][y] + board[nx][ny]:
                visited[nx][ny] = visited[x][y] + board[nx][ny]
                q.append((nx, ny))
    return visited[-1][-1]

problem = 1
while True:
    N = int(input())
    if N == 0: break
    
    board = [list(map(int, input().split())) for _ in range(N)]
    answer = bfs(N, board)
    print(f"Problem {problem}: {answer}")
    problem += 1
    