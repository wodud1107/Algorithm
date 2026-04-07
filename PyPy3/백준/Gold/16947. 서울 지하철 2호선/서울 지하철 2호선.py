import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
graph = [[] for _ in range(N + 1)]
degree = [0] * (N + 1)
for i in range(N):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    degree[a] += 1
    degree[b] += 1
    
is_cycle = [True] * (N + 1)
q = deque()
for i in range(1, N + 1):
    if (degree[i] == 1): q.append(i)

while q:
    curr = q.popleft()
    
    is_cycle[curr] = False
    
    for next in graph[curr]:
        degree[next] -= 1
        if (degree[next] == 1):
            q.append(next)

dist = [-1] * (N + 1)
dist_q = deque()
for i in range(1, N + 1):
    if (is_cycle[i]):
        dist[i] = 0
        dist_q.append(i)

while dist_q:
    curr = dist_q.popleft()
    
    for next in graph[curr]:
        if (dist[next] != -1): continue
        dist[next] = dist[curr] + 1
        dist_q.append(next)

print(*dist[1:], sep = ' ')