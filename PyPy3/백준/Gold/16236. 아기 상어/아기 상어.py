import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

shark_size = 2
s_x, s_y = 0, 0
for x in range(N):
    for y in range(N):
        if board[x][y] == 9:
            s_x, s_y = x, y
            
def find(board, size):
    eat = []
    for x in range(N):
        for y in range(N):
            if 0 < board[x][y] < size and board[x][y] != 9:
                eat.append((x, y))
    
    return eat

def init_board(board, x, y):
    temp_board = [row[:] for row in board]
    for i in range(N):
        for j in range(N):
            if temp_board[i][j] == 9: temp_board[i][j] = 0
    temp_board[x][y] = 9
    visited = [[-1] * N for _ in range(N)]
    visited[x][y] = 0
    q = deque([(x, y)])
    eat = find(temp_board, shark_size)
    return q, eat, visited, temp_board

q, eat, visited, board = init_board(board, s_x, s_y)
eat_cnt = 0
time = 0
while q:
    x, y = q.popleft()
    
    if not eat: break
    
    goal_x, goal_y = 21, 21
    min_time = float('inf')
    for (e_x, e_y) in eat:
        if visited[e_x][e_y] == -1: continue
        if min_time > visited[e_x][e_y]:
            min_time = visited[e_x][e_y]
            goal_x, goal_y = e_x, e_y
    if x == goal_x and y == goal_y:
        q, eat, visited, board = init_board(board, x, y)
        eat_cnt += 1
        time += min_time
        
    if eat_cnt == shark_size:
        eat_cnt = 0
        shark_size += 1
        eat = find(board, shark_size)
    
    for (dx, dy) in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        nx, ny = x + dx, y + dy
        if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == -1:
            if board[nx][ny] <= shark_size:
                visited[nx][ny] = visited[x][y] + 1
                q.append((nx, ny))
                
print(time)