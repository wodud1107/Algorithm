import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())

def bfs():
    q = deque([N])
    visited = [-1 for _ in range(100_001)]
    visited[N] = 0
    
    min_time = float('inf')
    ways = 0
    while q:
        X = q.popleft()
        
        if X == K:
            if min_time >= visited[K]:
                min_time = visited[K]
                ways += 1
                
            visited[K] = min_time
            continue
        
        for next in (X + 1, X - 1, 2 * X):
            if 0 <= next <= 100_000 and (visited[next] == -1 or visited[next] == visited[X] + 1):
                visited[next] = visited[X] + 1
                q.append(next)
            
    return visited[K], ways

min_time, ways = bfs()
print(min_time)
print(ways)