import sys
input = sys.stdin.readline

N = int(input())
board = [[0] * N for _ in range(N)]
dirts = []
jewelry = []
for i in range(N):
    ls = list(map(int, input().split()))
    for j in range(N):
        if ls[j] == 1: dirts.append((i, j))
        elif ls[j] == 2: jewelry.append((i, j))
        board[i][j] = ls[j]

def cut(board, dirts, jewelry, dir):
    if len(jewelry) == 1 and len(dirts) == 0:
        return 1
    
    elif len(jewelry) != len(dirts) + 1:
        return 0
    
    row = len(board)
    col = len(board[0])
    
    cnt = 0
    if dir:
        for (i, _) in dirts:
            if 2 in board[i]:
                continue
            
            if i == 0 and i == row - 1:
                continue
            
            cut1 = [[0] * col for _ in range(i)]
            cut2 = [[0] * col for _ in range(row - 1 - i)]
            jewelry1 = []
            dirts1 = []
            for r in range(i):
                for c in range(col):
                    if board[r][c] == 1: dirts1.append((r, c))
                    elif board[r][c] == 2: jewelry1.append((r, c))
                    cut1[r][c] = board[r][c]

            cnt1 = cut(cut1, dirts1, jewelry1, False)
            if cnt1 == 0: continue
            
            jewelry2 = []
            dirts2 = []
            for r in range(row - 1 - i):
                for c in range(col):
                    if board[r + i + 1][c] == 1: dirts2.append((r, c))
                    elif board[r + i + 1][c] == 2: jewelry2.append((r, c))
                    cut2[r][c] = board[r + i + 1][c]
            
            cnt2 = cut(cut2, dirts2, jewelry2, False)
            if cnt2 == 0: continue

            cnt += cnt1 * cnt2
            
    else:
        for (_, j) in dirts:
            can_cut = True
            for rows in board:
                if rows[j] == 2:
                    can_cut = False
            
            if j == 0 and j == col - 1:
                continue
            
            if can_cut:
                cut1 = [[0] * j for _ in range(row)]
                cut2 = [[0] * (col - 1 - j) for _ in range(row)]
                jewelry1 = []
                dirts1 = []
                for r in range(row):
                    for c in range(j):
                        if board[r][c] == 1: dirts1.append((r, c))
                        elif board[r][c] == 2: jewelry1.append((r, c))
                        cut1[r][c] = board[r][c]
                        
                cnt1 = cut(cut1, dirts1, jewelry1, True)
                if cnt1 == 0: continue
                
                jewelry2 = []
                dirts2 = []
                for r in range(row):
                    for c in range(col - j - 1):
                        if board[r][c + j + 1] == 1: dirts2.append((r, c))
                        elif board[r][c + j + 1] == 2: jewelry2.append((r, c))
                        cut2[r][c] = board[r][c + j + 1]
                
                cnt2 = cut(cut2, dirts2, jewelry2, True)
                if cnt2 == 0: continue
            
                cnt += cnt1 * cnt2
                
    return cnt

answer = cut(board, dirts, jewelry, True) + cut(board, dirts, jewelry, False)
print(answer if answer else -1)