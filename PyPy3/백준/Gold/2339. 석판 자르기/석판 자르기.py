import sys
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

def cut(r1, r2, c1, c2, dir):
    if r1 > r2 or c1 > c2:
        return 0
    
    jewel_cnt = 0
    dirt_cnt = 0
    
    for i in range(r1, r2 + 1):
        for j in range(c1, c2 + 1):
            if board[i][j] == 2: jewel_cnt += 1
            elif board[i][j] == 1: dirt_cnt += 1
    
    if jewel_cnt == 1 and dirt_cnt == 0: return 1
    if jewel_cnt != dirt_cnt + 1: return 0
    
    cnt = 0
    if dir:
        for i in range(r1, r2 + 1):
            has_dirt = False
            has_jewel = False
            for j in range(c1, c2 + 1):
                if board[i][j] == 1: has_dirt = True
                if board[i][j] == 2: has_jewel = True

            if has_dirt and not has_jewel:
                res1 = cut(r1, i - 1, c1, c2, False)
                res2 = cut(i + 1, r2, c1, c2, False)
                cnt += res1 * res2
            
    else:
        for j in range(c1, c2 + 1):
            has_dirt = False
            has_jewel = False
            for i in range(r1, r2 + 1):
                if board[i][j] == 1: has_dirt = True
                if board[i][j] == 2: has_jewel = True
                
            if has_dirt and not has_jewel:
                res1 = cut(r1, r2, c1, j - 1, True)
                res2 = cut(r1, r2, j + 1, c2, True)
                cnt += res1 * res2
            
    return cnt

answer = cut(0, N - 1, 0, N - 1, True) + cut(0, N - 1, 0, N - 1, False)
print(answer if answer else -1)