import sys
from itertools import combinations
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())

board = [[0 for _ in range(M)] for _ in range(N)]
empties  = []
viruses = []
for i in range(N):
    temp = list(map(int, input().split()))
    for j in range(M):
        board[i][j] = temp[j]
        
        if temp[j] == 0:
            empties.append((i, j))
            
        elif temp[j] == 2:
            viruses.append((i, j))

def spread_virus(board):
    queue = deque(viruses)
    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    while queue:
        x, y = queue.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < N and 0 <= ny < M and board[nx][ny] == 0:
                board[nx][ny] = 2
                queue.append((nx, ny))

max_safe = 0
for walls in combinations(empties, 3):
    temp_board = [row[:] for row in board]
    
    for (r, c) in walls:
        temp_board[r][c] = 1
        
    spread_virus(temp_board)
    
    safe = 0
    for i in range(N):
        for j in range(M):
            if temp_board[i][j] == 0: safe += 1
            
    max_safe = max(max_safe, safe)
    
print(max_safe)