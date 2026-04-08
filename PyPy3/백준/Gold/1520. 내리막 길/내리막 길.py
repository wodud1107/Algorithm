import sys
import heapq
input = sys.stdin.readline

M, N = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(M)]

q = [(-board[0][0], 0, 0)]
dp = [[0] * N for _ in range(M)]
dp[0][0] = 1
while q:
    height, x, y = heapq.heappop(q)
    height = -height
        
    for (dx, dy) in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        nx = x + dx
        ny = y + dy
        
        if (0 <= nx < M and 0 <= ny < N):
            if (height > board[nx][ny]):
                if (dp[nx][ny] == 0):
                    heapq.heappush(q, (-board[nx][ny], nx, ny))
                dp[nx][ny] += dp[x][y]
                
print(dp[-1][-1])