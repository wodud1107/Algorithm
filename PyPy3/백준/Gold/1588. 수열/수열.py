import sys
input = sys.stdin.readline

init = int(input())
L = int(input())
R = int(input())
N = int(input())

mem = [[None] * (N + 1) for _ in range(4)]
rule = {1: [1, 3, 2], 2: [2, 1, 1], 3: [2, 3, 2]}

def get_counts(num, time):
    if time == 0:
        res = [0, 0, 0]
        res[num - 1] = 1
        return res
    if mem[num][time] is not None:
        return mem[num][time]
    
    c1 = get_counts(rule[num][0], time - 1)
    c2 = get_counts(rule[num][1], time - 1)
    c3 = get_counts(rule[num][2], time - 1)
    
    mem[num][time] = [c1[i] + c2[i] + c3[i] for i in range(3)]
    return mem[num][time]

def solve(num, time, start, end):
    if end < L or start > R:
        return [0, 0, 0]

    if L <= start and end <= R:
        return get_counts(num, time)
    
    if time > 0:
        step = (end - start + 1) // 3
        mid1 = start + step
        mid2 = start + 2 * step
        
        r1 = solve(rule[num][0], time - 1, start, mid1 - 1)
        r2 = solve(rule[num][1], time - 1, mid1, mid2 - 1)
        r3 = solve(rule[num][2], time - 1, mid2, end)
        return [r1[i] + r2[i] + r3[i] for i in range(3)]
    else:
        res = [0, 0, 0]
        res[num - 1] = 1
        return res

total_len = 3 ** N
answer = solve(init, N, 0, total_len - 1)
print(*answer)