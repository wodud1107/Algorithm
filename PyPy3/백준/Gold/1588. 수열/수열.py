import sys
input = sys.stdin.readline

init = int(input())
L = int(input())
R = int(input())
N = int(input())

dp = [[[0] * 3 for _ in range(4)] for _ in range(N + 1)]

for num in range(1, 4):
    dp[0][num][num - 1] = 1
    
rules = {1: [1, 3, 2], 2: [2, 1, 1], 3: [2, 3, 2]}

for t in range(1, N + 1):
    for num in range(1, 4):
        r1, r2, r3 = rules[num]
        for i in range(3):
            dp[t][num][i] = dp[t - 1][r1][i] + dp[t - 1][r2][i] + dp[t - 1][r3][i]

def get_counts(num, time, start, end):
    if end < L or start > R:
        return [0, 0, 0]

    if L <= start and end <= R:
        return dp[time][num]
    
    res = [0, 0, 0]
    if time == 0:
        res[num - 1] = 1
        return res
    
    step = (end - start + 1) // 3
    curr_start = start
    for next_num in rules[num]:
        sub = get_counts(next_num, time - 1, curr_start, curr_start + step - 1)
        for i in range(3):
            res[i] += sub[i]
        curr_start += step
    
    return res

total_len = 3 ** N
answer = get_counts(init, N, 0, total_len - 1)
print(*answer)