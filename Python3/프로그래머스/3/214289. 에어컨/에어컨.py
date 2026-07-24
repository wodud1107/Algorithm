def solution(temperature, t1, t2, a, b, onboard):
    OFFSET = 10
    MAX_TEMP = 50
    
    temperature += OFFSET
    t1 += OFFSET
    t2 += OFFSET
    
    INF = float('inf')
    n = len(onboard)
    
    dp = [[INF] * (MAX_TEMP + 1) for _ in range(n)]
    dp[0][temperature] = 0
    
    for i in range(n - 1):
        for j in range(MAX_TEMP + 1):
            if dp[i][j] == INF: continue
            nxt_temp = j
            if j < temperature: nxt_temp = j + 1
            elif j > temperature: nxt_temp = j - 1
            
            if onboard[i + 1] == 0 or (t1 <= nxt_temp <= t2):
                dp[i + 1][nxt_temp] = min(dp[i + 1][nxt_temp], dp[i][j])
            if onboard[i + 1] == 0 or (t1 <= j <= t2):
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b)
                
            if j - 1 >= 0:
                nxt_temp = j - 1
                if onboard[i + 1] == 0 or (t1 <= nxt_temp <= t2):
                    dp[i + 1][nxt_temp] = min(dp[i + 1][nxt_temp], dp[i][j] + a)
            if j + 1 <= MAX_TEMP:
                nxt_temp = j + 1
                if onboard[i + 1] == 0 or (t1 <= nxt_temp <= t2):
                    dp[i + 1][nxt_temp] = min(dp[i + 1][nxt_temp], dp[i][j] + a)
    return min(dp[-1])