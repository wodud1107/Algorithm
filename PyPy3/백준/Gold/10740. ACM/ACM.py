import sys
from itertools import permutations
input = sys.stdin.readline

N = int(input())
scores = [list(map(int, input().split())) for _ in range(3)]

dp = [[5 * N] * 3 for _ in range(1 << 3)]
for i in range(N):
    new_dp = [[5 * N] * 3 for _ in range(1 << 3)]
    for mask in range(1, 1 << 3):
        for p in range(3):
            if mask & (1 << p):
                prev_mask = mask ^ (1 << p)
                
                if prev_mask == 0:
                    if i == 0: new_dp[mask][p] = scores[p][i]
                    else: new_dp[mask][p] = dp[mask][p] + scores[p][i]
                
                else:
                    result = 5 * N
                    for prev_p in range(3):
                        if prev_mask & (1 << prev_p):
                            result = min(result, dp[prev_mask][prev_p])
                            
                    stay = dp[mask][p]
                    new_dp[mask][p] = min(result, stay) + scores[p][i]
    dp = new_dp

print(min(dp[7]))