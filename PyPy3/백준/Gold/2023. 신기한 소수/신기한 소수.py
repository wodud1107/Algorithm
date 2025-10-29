import sys
import math
input = sys.stdin.readline

N = int(input())

def is_prime(N):
    if (N <= 1): return False
    if (N <= 3): return True
    if (N % 2 == 0 or N % 3 == 0): return False
    
    for i in range(5, int(math.sqrt(N)) + 1, 6):
        if (N % i == 0 or N % (i + 2) == 0): return False
        
    return True

result = set([2, 3, 5, 7])
start = [2, 3, 5, 7]

def dfs(go):
    if (go >= 10 ** N): return
    
    for i in range(10):
        if (is_prime(go + i)):
            result.add(go + i)
            dfs((go + i) * 10)

for i in start:
    dfs(i)
    
answer = []

for i in result:
    if i in range(2 * 10 ** (N - 1), 10 ** N):
        answer.append(i)

answer.sort()

print(*answer, sep = "\n")