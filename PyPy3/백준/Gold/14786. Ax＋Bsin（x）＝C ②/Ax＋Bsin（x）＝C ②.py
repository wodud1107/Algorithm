import sys
import math
input = sys.stdin.readline

A, B, C = map(int, input().split())

s, e = 0, 100_000

while e - s > 1e-9:
    mid = (s + e) / 2
    
    if (A * mid + B * math.sin(mid)) ** 2 > C ** 2:
        e = mid
    elif (A * mid + B * math.sin(mid)) ** 2 < C ** 2:
        s = mid
    else:
        break
    
print(e)
