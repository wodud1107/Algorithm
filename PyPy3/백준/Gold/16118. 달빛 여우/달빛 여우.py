import sys
import heapq
input = sys.stdin.readline
INF = 1e15

N, M = map(int, input().split())

fox_graph = [[] for _ in range(N + 1)]
wolf_graph = [[] for _ in range(2 * N + 1)]
for i in range(M):
    a, b, d = map(int, input().split())
    d *= 2
    fox_graph[a].append((b, d))
    fox_graph[b].append((a, d))

    wolf_graph[a].append((b + N, d // 2))
    wolf_graph[b].append((a + N, d // 2))
    wolf_graph[a + N].append((b, 2 * d))
    wolf_graph[b + N].append((a, 2 * d))
    
    
fox_time = [INF] * (N + 1)
fox_time[1] = 0
fox_q = [(0, 1)]
while fox_q:
    distance, curr = heapq.heappop(fox_q)
    
    if (fox_time[curr] < distance): continue
    
    for (next, dist) in fox_graph[curr]:
        next_dist = distance + dist
        if (next_dist < fox_time[next]):
            fox_time[next] = next_dist
            heapq.heappush(fox_q, (next_dist, next))
            
wolf_time = [INF] * (2 * N + 1)
wolf_time[1] = 0
wolf_q = [(0, 1)]
while wolf_q:
    distance, curr = heapq.heappop(wolf_q)
    
    if (wolf_time[curr] < distance): continue
    
    for (next, dist) in wolf_graph[curr]:
        next_dist = distance + dist
        if (next_dist < wolf_time[next]):
            wolf_time[next] = next_dist
            heapq.heappush(wolf_q, (next_dist, next))
            
answer = 0
for i in range(1, N + 1):
    if (fox_time[i] < min(wolf_time[i], wolf_time[i + N])): answer += 1
    
print(answer)