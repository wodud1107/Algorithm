import sys
input = sys.stdin.readline

s = [input().strip() for _ in range(3)]
s.sort(key=len)
longest = s[2]
dp = [[[0] * 101 for _ in range(101)] for _ in range(101)]

for i in range(1, len(s[0]) + 1):
    for j in range(1, len(s[1]) + 1):
        for k in range(1, len(s[2]) + 1):
            shortest = s[0][i - 1]
            middle = s[1][j - 1]
            longest = s[2][k - 1]
            
            if shortest == middle == longest:
                dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1
            else:
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1])

print(dp[len(s[0])][len(s[1])][len(s[2])])