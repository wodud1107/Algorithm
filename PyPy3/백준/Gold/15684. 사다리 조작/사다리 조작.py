import sys
input = sys.stdin.readline

N, M, H = map(int, input().split())

if M == 0: print(0); exit(0)

ladders = [[i for i in range(N + 1)] for _ in range(H + 1)]
for _ in range(M):
    (a, b) = map(int, input().split())
    ladders[a][b] = b + 1
    ladders[a][b + 1] = b
    
def down(ladders, i):
    current = i
    for r in range(1, H + 1):
        current = ladders[r][current]
        
    if current == i: return True
    return False

def check_all_down(ladders):
    for n in range(1, N + 1):
        current = n
        for r in range(1, H + 1):
            current = ladders[r][current]
            
        if current != n: return False
    return True

def dfs(current_count, x, y, target_count):
    if current_count == target_count:
        if check_all_down(ladders):
            print(target_count)
            exit(0)
        return
    
    for i in range(x, H + 1):
        start = y if i == x else 1
        
        for j in range(start, N):
            if ladders[i][j] == j and ladders[i][j + 1] == j + 1:
                ladders[i][j] = j + 1
                ladders[i][j + 1] = j
                
                dfs(current_count + 1, i, j + 2, target_count)
                
                ladders[i][j] = j
                ladders[i][j + 1] = j + 1

for count in range(4):
    dfs(0, 1, 1, count)
        
print(-1)