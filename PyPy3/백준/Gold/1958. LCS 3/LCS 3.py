import sys
input = sys.stdin.readline

s1 = input().strip()
s2 = input().strip()
s3 = input().strip()
dp = [[[0] * 101 for _ in range(101)] for _ in range(101)]

for i in range(1, len(s1) + 1):
    for j in range(1, len(s2) + 1):
        for k in range(1, len(s3) + 1):
            c1 = s1[i - 1]
            c2 = s2[j - 1]
            c3 = s3[k - 1]
            
            if c1 == c2 == c3:
                dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1
            else:
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1])

print(dp[len(s1)][len(s2)][len(s3)])