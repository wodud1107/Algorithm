import sys
input = sys.stdin.readline

MOD = 1_000_000_000
N = int(input())

dp = [[[0] * 1024 for _ in range(10)] for _ in range(N + 1)]

if N < 9: print(0); exit(0)

for j in range(1, 10):
    dp[1][j][1 << j] = 1

for i in range(2, N + 1):
    for j in range(10):
        for mask in range(1024):
            if dp[i - 1][j][mask] == 0:
                continue
            
            if j > 0:
                next_mask = mask | (1 << (j - 1))
                dp[i][j - 1][next_mask] = (dp[i][j - 1][next_mask] + dp[i - 1][j][mask]) % MOD
                
            if j < 9:
                next_mask = mask | (1 << (j + 1))
                dp[i][j + 1][next_mask] = (dp[i][j + 1][next_mask] + dp[i - 1][j][mask]) % MOD
                
ans = 0
for j in range(10):
    ans = (ans + dp[N][j][1023]) % MOD
print(ans)