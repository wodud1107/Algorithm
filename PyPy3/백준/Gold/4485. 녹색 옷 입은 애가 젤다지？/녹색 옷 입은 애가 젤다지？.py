import sys
import heapq
input = sys.stdin.readline

def bfs(N, board):
    dist = [[float('inf')] * N for _ in range(N)]
    dist[0][0] = board[0][0]
    q = [(board[0][0], 0, 0)]
    
    while q:
        cost, x, y = heapq.heappop(q)
        
        if x == N - 1 and y == N - 1:
            return cost
        
        if cost > dist[x][y]:
            continue
        
        for (dx, dy) in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            nx, ny = x + dx, y + dy
            
            if 0 <= nx < N and 0 <= ny < N and dist[nx][ny] > cost + board[nx][ny]:
                dist[nx][ny] = cost + board[nx][ny]
                heapq.heappush(q, (dist[nx][ny], nx, ny))

problem = 1
while True:
    N = int(input())
    if N == 0: break
    
    board = [list(map(int, input().split())) for _ in range(N)]
    answer = bfs(N, board)
    print(f"Problem {problem}: {answer}")
    problem += 1
    