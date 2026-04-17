import sys
import heapq
input = sys.stdin.readline

N, M = map(int, input().split())
univ = [-1] + [0 if i == 'M' else 1 for i in input().split()]
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v, d = map(int, input().split())
    graph[u].append((v, d))
    graph[v].append((u, d))
    
visited = [False] * (N + 1)
visited[1] = True
q = []

for nxt, dist in graph[1]:
    if (univ[1] != univ[nxt]):
        heapq.heappush(q, (dist, 1, nxt))

total = 0
cnt = 0
while q and cnt < N - 1:
    d, f, t = heapq.heappop(q)
    
    if visited[t]: continue
    visited[t] = True
    total += d
    cnt += 1
    
    for nxt, dist in graph[t]:
        if (univ[t] == univ[nxt]): continue
        if (visited[nxt]): continue
        heapq.heappush(q, (dist, t, nxt))
        
if (cnt < N - 1): print(-1)
else: print(total)