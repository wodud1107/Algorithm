def solution(money):
    n = len(money)
    dp = [0] * n
    dp[0] = money[0]
    dp[1] = max(money[0], money[1])
    for i in range(2, n - 1):
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1])
        
    dp2 = [0] * n
    dp2[0] = 0
    dp2[1] = money[1]
    for i in range(2, n):
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1])
    return max(dp[n - 2], dp2[n - 1])