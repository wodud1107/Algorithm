import sys
input = sys.stdin.readline

'''
수 하나만 가지고 있는 수열
1 -> 132 2 -> 211 3 -> 232 로 바뀜 1초마다 동시에
123 으로만 이루어짐
N 초후 L, R 사이 1,2,3 개수 구하기 0부터 인덱싱

계속 3등분해서 길이가 1일 때 판별
def later(seq):
    length = len(seq)
    if length == 1:
        if seq[0] == "1":
            return "132"
        elif seq[0] == "2":
            return "211"
        else:
            return "232"
    return later(seq[:length // 3]) + later(seq[length // 3:2 * length // 3]) + later(seq[2 * length // 3:])
'''

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