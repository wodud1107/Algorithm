import sys
input = sys.stdin.readline

N = int(input())

ls = [0]
for _ in range(1, N + 1):
    ls.append(int(input()))

ans_list = []
def dfs(start, current, visited):
    visited[current] = True
    next = ls[current]
    
    if not visited[next]:
        dfs(start, next, visited)
    elif next == start:
        ans_list.append(start)

for i in range(1, N + 1):
    visited = [False] * (N + 1)
    dfs(i, i, visited)

print(len(ans_list))
print(*ans_list, sep = '\n')