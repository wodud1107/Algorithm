import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
lines = []
for i in range(M):
    a, b, c = map(int, input().split())
    lines.append((a, b, c))
    
parent = [i for i in range(N + 1)]

def find(x):
    if parent[x] == x: return x
    parent[x] = find(parent[x])
    return parent[x]

def unite(a, b):
    a = find(a)
    b = find(b)
    if (a == b): return False
    parent[b] = a
    return True

lines.sort(key=lambda x: x[2])

total = 0
used = 0
for l in lines:
    (a, b, c) = l
    if (unite(a, b)):
        total += c
        used += 1
    
    if (used == N - 1): break

print(total)