import sys
from itertools import combinations
input = sys.stdin.readline

N, M, H = map(int, input().split())

if M == 0: print(0); exit(0)

ladders = [[i for i in range(N + 1)] for _ in range(H + 1)]
def make_row(ladders, a, b):
    ladders[a][b] = b + 1
    ladders[a][b + 1] = b

row = set()
for _ in range(M):
    (a, b) = map(int, input().split())
    row.add((a, b))
    if b - 1 > 0: row.add((a, b - 1))
    elif b + 1 < N: row.add((a, b + 1))
    make_row(ladders, a, b)
    
remaining = [(a, b) for b in range(1, N) for a in range(1, H + 1) if (a, b) not in row]

def down(ladders, i):
    tracks = [i]
    current = i
    for r in range(1, H + 1):
        current = ladders[r][current]
        tracks.append(current)
        
    if tracks[-1] == i: return True
    return False

is_broken = False
for n in range(1, N + 1):
    if not down(ladders, n):
        is_broken = True
        break

if not is_broken: print(0); exit(0)

for count in range(3):
    for rows in combinations(remaining, count + 1):
        temp_ladders = [row[:] for row in ladders]
        temp_row = row.copy()
        for add_row in rows:
            if add_row[1] - 1 > 0: temp_row.add((add_row[0], add_row[1] - 1))
            elif add_row[1] + 1 < N: temp_row.add((add_row[0], add_row[1] + 1))
            
            if add_row not in temp_row:
                make_row(temp_ladders, add_row[0], add_row[1])
        
        is_broken = False
        for n in range(1, N + 1):
            if not down(temp_ladders, n):
                is_broken = True
                break
        
        if is_broken: continue
        else: print(count + 1); exit(0)
        
print(-1)