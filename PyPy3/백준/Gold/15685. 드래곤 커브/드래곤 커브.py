import sys
input = sys.stdin.readline

N = int(input())
dr_curve = [list(map(int, input().split())) for _ in range(N)]

board = [[False] * 101 for _ in range(101)]

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

for curve in dr_curve:
    x, y, d, g = curve[0], curve[1], curve[2], curve[3]

    dir = [d]
    for _ in range(g):
        next = [(curr_d + 1) % 4 for curr_d in reversed(dir)]
        dir.extend(next)
    
    board[x][y] = True
    curr_x, curr_y = x, y
    for dr in dir:
        curr_x += dx[dr]
        curr_y += dy[dr]
        
        if 0 <= curr_x < 101 and 0 <= curr_y < 101:
            board[curr_x][curr_y] = True

answer = 0
for i in range(100):
    for j in range(100):
        if board[i][j] and board[i][j + 1] and board[i + 1][j] and board[i + 1][j + 1]:
            answer += 1

print(answer)