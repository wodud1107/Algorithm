import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * M for _ in range(N)]

max_val = max(map(max, board))
answer = 0
def dfs(cnt, S, x, y):
    global answer
    
    if S + max_val * (4 - cnt) <= answer: return
    if (cnt == 4):
        answer = max(answer, S)
        return
    
    for (dx, dy) in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        nx, ny = x + dx, y + dy

        if (0 <= nx < N and 0 <= ny < M):
            if (not visited[nx][ny]):
                if (cnt == 2):
                    visited[nx][ny] = True
                    dfs(cnt + 1, S + board[nx][ny], x, y)
                    visited[nx][ny] = False
                
                visited[nx][ny] = True
                dfs(cnt + 1, S + board[nx][ny], nx, ny)
                visited[nx][ny] = False

for i in range(N):
    for j in range(M):
        visited[i][j] = True
        dfs(1, board[i][j], i, j)
        visited[i][j] = False

print(answer)