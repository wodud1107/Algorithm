import sys
input = sys.stdin.readline

N = int(input())
liquid = list(map(int, input().split()))
liquid.sort()

minimum = 3_000_000_000
answer = [0] * 3
for i in range(0, len(liquid) - 1):
    l = i + 1
    r = len(liquid) - 1
    
    while (l < r):
        S = liquid[i] + liquid[l] + liquid[r]
        if (abs(S) < minimum):
            minimum = abs(S)
            answer[0] = liquid[i]
            answer[1] = liquid[l]
            answer[2] = liquid[r]
            
        if (S < 0): l += 1
        else: r -= 1
        
print(*answer)