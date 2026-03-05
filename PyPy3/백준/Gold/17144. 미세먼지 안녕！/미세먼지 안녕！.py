import sys
from collections import deque
input = sys.stdin.readline

R, C, T = map(int, input().split())
board = [[0 for _ in range(C)] for _ in range(R)]
purifier = []
dirts = []
for i in range(R):
    row = list(map(int, input().split()))
    for j in range(C):
        board[i][j] = row[j]
        
        if row[j] == -1:
            purifier.append((i, j))
            
        elif row[j] > 0:
            dirts.append((i, j))
            
def spread_dirts(board):
    temp_board = [row[:] for row in board]
    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    queue = deque(dirts)
    while queue:
        (r, c) = queue.popleft()
        
        count = 0
        for i in range(4):
            nx = r + dx[i]
            ny = c + dy[i]
            
            if (nx, ny) in purifier:
                continue
            
            if 0 <= nx < R and 0 <= ny < C:
                temp_board[nx][ny] += board[r][c] // 5
                count += 1
                
        temp_board[r][c] -= board[r][c] // 5 * count
    
    return temp_board

def purify(board):
    temp_board = [row[:] for row in board]
    
    upper, lower = purifier[0], purifier[1]
    
    # 청정기 바로 옆
    temp_board[upper[0]][1] = 0
    temp_board[lower[0]][1] = 0
    
    # 청정기 우측
    for x in range(1, C - 1):
        temp_board[upper[0]][x + 1] = board[upper[0]][x]
        temp_board[lower[0]][x + 1] = board[lower[0]][x]
    
    # 청정기 벽에 부딪혀서 위로
    for y in range(upper[0], 0, -1):
        temp_board[y - 1][-1] = board[y][-1]
        
    # 청정기 벽에 부딪혀서 아래로
    for y in range(lower[0], R - 1):
        temp_board[y + 1][-1] = board[y][-1]
        
    # 청정기 벽에 부딪히고 다시 청정기쪽으로 왼쪽
    for x in range(C - 1, 0, -1):
        temp_board[0][x - 1] = board[0][x]
        temp_board[-1][x - 1] = board[-1][x]
        
    # 청정기 근처 아래로
    for y in range(0, upper[0] - 1):
        temp_board[y + 1][0] = board[y][0]
    
    # 청정기 근처 위로
    for y in range(R - 1, lower[0] + 1, -1):
        temp_board[y - 1][0] = board[y][0]
        
    return temp_board
    
for _ in range(T):
    board = spread_dirts(board)
    board = purify(board)
    
    new_dirts = []
    for i in range(R):
        for j in range(C):
            if board[i][j] > 0: new_dirts.append((i, j))
    
    dirts = new_dirts

answer = 0
for i in range(R):
    for j in range(C):
        if board[i][j] > 0: answer += board[i][j]
        
print(answer)