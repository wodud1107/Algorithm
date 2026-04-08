import sys
input = sys.stdin.readline

N, K = map(int, input().split())
board = [list(map(int, list(input().strip()))) for _ in range(N)]

def dfs(num, x, y, visited):
    stack = [(x, y)]
    connected = [(x, y)]
    visited[x][y] = True
    
    while stack:
        curr_x, curr_y = stack.pop()
        for (dx, dy) in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            nx = curr_x + dx
            ny = curr_y + dy
            
            if (0 <= nx < N and 0 <= ny < 10 and board[nx][ny] == num and not visited[nx][ny]):
                visited[nx][ny] = True
                connected.append((nx, ny))
                stack.append((nx, ny))
    return connected
            
while (True):
    visited = [[False] * 10 for _ in range(N)]
    removable = []
    found_any = False
    for i in range(N):
        for j in range(10):
            if (board[i][j] == 0 or visited[i][j]): continue
            connected = dfs(board[i][j], i, j, visited)
            if (len(connected) >= K):
                removable.extend(connected)
                found_any = True
            
    if (not found_any): break
    
    for (i, j) in removable:
        board[i][j] = 0

    for j in range(10):
        stack = []
        for i in range(N):
            if (board[i][j] != 0): stack.append(board[i][j])
            
        for i in range(N - 1, -1, -1):
            if stack: board[i][j] = stack.pop()
            else: board[i][j] = 0
        
for row in board:
    print(''.join(map(str, row)))