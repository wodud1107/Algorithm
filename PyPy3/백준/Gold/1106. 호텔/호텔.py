import sys
input = sys.stdin.readline

C, N = map(int, input().split())

ls = []
for i in range(N):
    ls.append(list(map(int, input().split())))
    
dp = [[float("inf")] * (C + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    cost = ls[i - 1][0]
    people = ls[i - 1][1]
    for j in range(1, C + 1):
        dp[i][j] = (j + people - 1) // people * cost
        for k in range(j + 1):
            c = (j - k + people - 1) // people * cost
            dp[i][j] = min(dp[i - 1][k] + c, dp[i][j])
        
print(dp[N][C])