import sys
input = sys.stdin.readline

S = input().rstrip()
T = input().rstrip()

def solve(T):
    if (T == S):
        return 1
    
    if (len(T) < len(S)):
        return 0
    
    if (T[-1] == 'A'):
        if solve(T[:-1]):
            return 1
        
    if (T[-1] == 'B'):
        if solve("".join(T[:-1][::-1])):
            return 1
        
    return 0

print(solve(T))