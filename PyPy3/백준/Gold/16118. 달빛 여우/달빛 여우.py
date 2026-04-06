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
    
fox_dist = [INF] * (N + 1)
wolf_dist = [INF] * (2 * N + 1)
def dijkstra(dist, graph):
    dist[1] = 0
    q = [(0, 1)]
    while q:
        distance, curr = heapq.heappop(q)
        
        if (dist[curr] < distance): continue
        
        for (next, d) in graph[curr]:
            next_dist = distance + d
            if (next_dist < dist[next]):
                dist[next] = next_dist
                heapq.heappush(q, (next_dist, next))
            
dijkstra(fox_dist, fox_graph)
dijkstra(wolf_dist, wolf_graph)
            
answer = 0
for i in range(1, N + 1):
    if (fox_dist[i] < min(wolf_dist[i], wolf_dist[i + N])): answer += 1
    
print(answer)