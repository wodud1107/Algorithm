import sys
input = sys.stdin.readline

n, m = map(int, input().split())
tree = [0] + list(map(int, input().split()))
dp = [0 for _ in range(n + 1)]

for i in range(m):
    who, value = map(int, input().split())
    dp[who] += value

for who in range(2, n + 1):
    dp[who] += dp[tree[who]]
        
print(*dp[1:], sep=' ')