import sys
from itertools import combinations
input = sys.stdin.readline

N, M = map(int, input().split())

board = []
for i in range(N):
    board.append(list(map(int, input().split())))
    
house = []
chicken = []
for i in range(N):
    for j in range(N):
        if (board[i][j] == 1): house.append((i, j))
        elif (board[i][j] == 2): chicken.append((i, j))

chicken_combos = list(combinations(chicken, M))

min_dist = float('inf')

for combo in chicken_combos:
    current_dist = 0
    
    for h in house:
        min_chick = float('inf')
        for c in combo:
            dist = abs(h[0] - c[0]) + abs(h[1] - c[1])
            min_chick = min(min_chick, dist)
            
        current_dist += min_chick
        
    min_dist = min(min_dist, current_dist)

print(min_dist)