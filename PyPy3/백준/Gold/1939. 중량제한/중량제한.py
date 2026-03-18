import sys
import heapq
input = sys.stdin.readline

N, M = map(int, input().split())
ls = [[] for _ in range(N + 1)]
for _ in range(M):
    A, B, C = map(int, input().split())
    ls[A].append((B, C))
    ls[B].append((A, C))

fc1, fc2 = map(int, input().split())

weight = [0] * (N + 1)
weight[fc1] = float('inf')
q = [(-float('inf'), fc1)]
while q:
    cost, curr = heapq.heappop(q)
    cost = -cost

    if curr == fc2:
        print(cost)
        break
    
    if cost < weight[curr]: continue
    
    for (next, next_cost) in ls[curr]:
        new_cost = min(cost, next_cost)
        if new_cost > weight[next]:
            weight[next] = new_cost
            heapq.heappush(q, (-new_cost, next))
