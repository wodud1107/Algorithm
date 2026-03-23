import sys
input = sys.stdin.readline

N = int(input())
ls = [1]

nums = [1, 2, 3]

def is_good(ls):
    for i in range(1, len(ls) // 2 + 1):
        if ls[-i:] == ls[-2*i:-i]: return False
    return True

def solve(N, ls):
    if len(ls) == N:
        print(*ls, sep='')
        exit(0)
    
    for i in nums:
        ls.append(i)
        
        if is_good(ls):
            solve(N, ls)
        
        ls.pop()
    
solve(N, ls)