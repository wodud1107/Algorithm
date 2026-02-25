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
    for (i,j) in teachers:
        is_blocked = False
        for k in range(i, -1, -1):
            if not is_blocked:
                if board[k][j] == "S": return False
            if board[k][j] == "O":
                is_blocked = True
                
        is_blocked = False
        for k in range(i, N):
            if not is_blocked:
                if board[k][j] == "S": return False
            if board[k][j] == "O":
                is_blocked = True
                
        is_blocked = False
        for k in range(j, -1, -1):
            if not is_blocked:
                if board[i][k] == "S": return False
            if board[i][k] == "O":
                is_blocked = True

        is_blocked = False
        for k in range(j, N):
            if not is_blocked:
                if board[i][k] == "S": return False
            if board[i][k] == "O":
                is_blocked = True
            
    return True
        
for obs in combinations(empties, 3):
    temp_board = [row[:] for row in board]
    
    for (i, j) in obs:
        temp_board[i][j] = "O"
        
    if solve(temp_board):
        print("YES")
        exit(0)
            
print("NO")