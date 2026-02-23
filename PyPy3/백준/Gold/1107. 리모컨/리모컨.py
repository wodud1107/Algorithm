import sys
input = sys.stdin.readline

N = int(input())
M = int(input())

if M > 0:
    err = set((input().split()))
else: 
    err = set()

answer = abs(N - 100)

for nums in range(1_000_001):
    avail = str(nums)
    
    is_broken = False
    for a in avail:
        if a in err:
            is_broken = True
            break
        
    if not is_broken:
        _min = len(avail) + abs(N - nums)
        answer = min(_min, answer)
    
print(answer)