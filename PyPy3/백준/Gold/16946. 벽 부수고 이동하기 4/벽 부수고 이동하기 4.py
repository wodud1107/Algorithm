import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(map(int, input().strip())) for _ in range(N)]
cnt_map = [0] * (N * M + 2)
mark = 2

print_map = [row[:] for row in board]
for i in range(N):
    for j in range(M):
        if (board[i][j] == 0):
            board[i][j] = mark
            q = deque([(i, j)])
            cnt = 1
            while (q):
                x, y = q.popleft()
                
                for (dx, dy) in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                    nx, ny = x + dx, y + dy
                    
                    if (0 <= nx < N and 0 <= ny < M):
                        if (board[nx][ny] == 0):
                            board[nx][ny] = mark
                            cnt += 1
                            q.append((nx, ny))
            cnt_map[mark] = cnt
            mark += 1
            
for i in range(N):
    for j in range(M):
        if (board[i][j] == 1):
            mark_set = set()
            for (dx, dy) in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                nx, ny = i + dx, j + dy
                
                if (0 <= nx < N and 0 <= ny < M):
                    if (board[nx][ny] != 1): mark_set.add(board[nx][ny])
            
            for m in mark_set:
                print_map[i][j] += cnt_map[m] % 10
                
            print_map[i][j] %= 10
            
for row in print_map:
    print(''.join(map(str,row)))