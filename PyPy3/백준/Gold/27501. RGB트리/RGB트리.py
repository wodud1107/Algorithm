import sys
input = sys.stdin.readline

N = int(input())
graph = [[] for _ in range(N + 1)]
for i in range(N - 1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
light = [[0, 0, 0]]
for _ in range(N):
    light.append(list(map(int, input().split())))

dp = [row[:] for row in light]
visited = [False] * (N + 1)
visited[1] = True
def dfs(node):
    for child in graph[node]:
        if not visited[child]:
            visited[child] = True
            dfs(child)
            
            dp[node][0] += max(dp[child][1], dp[child][2])
            dp[node][1] += max(dp[child][0], dp[child][2])
            dp[node][2] += max(dp[child][0], dp[child][1])

dfs(1)

colors = [0] * (N + 1)
root_color = 0
for i in range(1, 3):
    if dp[1][i] > dp[1][root_color]:
        root_color = i 
colors[1] = root_color

def trace(node, parent):
    parent_color = colors[node]
    
    for child in graph[node]:
        if child != parent:
            best_color = -1
            max_val = -1
            
            for c in range(3):
                if c != parent_color:
                    if dp[child][c] > max_val:
                        max_val = dp[child][c]
                        best_color = c
            colors[child] = best_color
            trace(child, node)

trace(1, 0)

print(max(dp[1]))
rgb_map = ['R', 'G', 'B']
rgb = [rgb_map[colors[i]] for i in range(1, N + 1)]
print(*rgb, sep = '')