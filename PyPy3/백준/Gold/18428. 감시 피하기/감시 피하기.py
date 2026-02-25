import sys
from itertools import combinations
input = sys.stdin.readline

N = int(input())
board = [[0 for _ in range(N)] for _ in range(N)]
empties = []
teachers = []

for i in range(N):
    temp = list(map(str, input().split()))
    for j in range(N):
        board[i][j] = temp[j]
        
        if temp[j] == "X":
            empties.append((i, j))
            
        elif temp[j] == "T":
            teachers.append((i, j))    
            
def solve(board):
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    for (x,y) in teachers:
        for i in range(4):
            nx, ny = x, y
            
            while True:
                nx += dx[i]
                ny += dy[i]
                
                if not (0 <= nx < N and 0 <= ny < N): break
                if board[nx][ny] == "O": break
                if board[nx][ny] == "S": return False
    return True
    
for obs in combinations(empties, 3):
    temp_board = [row[:] for row in board]
    
    for (i, j) in obs:
        temp_board[i][j] = "O"
        
    if solve(temp_board):
        print("YES")
        exit(0)
            
print("NO")