import sys
import heapq
input = sys.stdin.readline
INF = 1e15

N, M = map(int, input().split())

graph = [[] for _ in range(N + 1)]
for i in range(M):
    a, b, d = map(int, input().split())
    graph[a].append((b, 2 * d))
    graph[b].append((a, 2 * d))
    
fox_time = [INF] * (N + 1)
fox_time[1] = 0
fox_q = [(0, 1)]
while fox_q:
    distance, curr = heapq.heappop(fox_q)
    
    if (fox_time[curr] < distance): continue
    
    for (next, dist) in graph[curr]:
        next_dist = distance + dist
        if (next_dist < fox_time[next]):
            fox_time[next] = next_dist
            heapq.heappush(fox_q, (next_dist, next))
            
wolf_time = [[INF] * (N + 1) for _ in range(2)]
wolf_time[0][1] = 0
wolf_q = [(0, 1, 0)]
while wolf_q:
    distance, curr, parity = heapq.heappop(wolf_q)
    
    if (wolf_time[parity][curr] < distance): continue
    
    for (next, dist) in graph[curr]:
        if (parity == 0):
            next_dist = distance + dist // 2
        else:
            next_dist = distance + 2 * dist
        next_parity = 1 - parity
        if (next_dist < wolf_time[next_parity][next]):
            wolf_time[next_parity][next] = next_dist
            heapq.heappush(wolf_q, (next_dist, next, next_parity))
            
answer = 0
for i in range(1, N + 1):
    best_wolf_time = min(wolf_time[0][i], wolf_time[1][i])
    if (fox_time[i] < best_wolf_time): answer += 1
    
print(answer)