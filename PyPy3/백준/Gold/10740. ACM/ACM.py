import sys
from itertools import permutations
input = sys.stdin.readline

N = int(input())

prefix = [[0] + list(map(int, input().split())) for _ in range(3)]
for i in range(3):
    for j in range(1, N + 1):
        prefix[i][j] += prefix[i][j - 1]
        
min_difficulty = 5 * N
for p in permutations(range(3)):
    p1, p2, p3 = p
    
    min_prev_diff = 5 * N
    for j in range(2, N):
        i = j - 1
        cur_diff = prefix[p1][i] - prefix[p2][i]
        min_prev_diff = min(min_prev_diff, cur_diff)
            
        result = min_prev_diff + prefix[p2][j] - prefix[p3][j] + prefix[p3][N]
        min_difficulty = min(min_difficulty, result)

print(min_difficulty)