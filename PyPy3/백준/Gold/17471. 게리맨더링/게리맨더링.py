import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
populate = [0] + list(map(int, input().split()))
graph = [[] for _ in range(N + 1)]
for i in range(1, N + 1):
    neighbor = list(map(int, input().split()))
    for j in range(1, neighbor[0] + 1):
        graph[i].append(neighbor[j])
        
def is_connected(group):
    if not group:
        return False
    
    start = group[0]
    q = deque([start])
    visited = set([start])
    while q:
        curr = q.popleft()
        
        for nxt in graph[curr]:
            if nxt in group and nxt not in visited:
                visited.add(nxt)
                q.append(nxt)
    
    return len(visited) == len(group)

answer = 1001
for i in range(1, (1 << N) - 1):
    group1 = []
    group2 = []
    
    for j in range(N):
        if (i & (1 << j)): group1.append(j + 1)
        else: group2.append(j + 1)
        
    if is_connected(group1) and is_connected(group2):
        pop1 = sum(populate[node] for node in group1)
        pop2 = sum(populate[node] for node in group2)
        answer = min(answer, abs(pop1 - pop2))

if (answer == 1001): print(-1)
else: print(answer)