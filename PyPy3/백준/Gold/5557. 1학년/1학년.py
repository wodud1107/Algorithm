import sys
input = sys.stdin.readline

N = int(input())
ls = list(map(int, input().split()))

dp = [[0]* 21 for _ in range(N - 1)]
dp[0][ls[0]] = 1

for i in range(1, N - 1):
    for j in range(21):
        if dp[i - 1][j]:
            if 0 <= j + ls[i] <= 20:
                dp[i][j + ls[i]] += dp[i - 1][j]
            if 0 <= j - ls[i] <= 20:
                dp[i][j - ls[i]] += dp[i - 1][j]
                
print(dp[-1][ls[-1]])