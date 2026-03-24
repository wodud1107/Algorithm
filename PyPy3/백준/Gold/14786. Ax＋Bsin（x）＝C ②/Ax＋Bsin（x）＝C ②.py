import sys
import math
input = sys.stdin.readline


A, B, C = map(int, input().split())

s, e = 0, 100_000

while s <= e:
    mid = (s + e) / 2
    
    if (A * mid + B * math.sin(mid)) ** 2 > C ** 2:
        e = mid - 10 ** (-9)
    elif (A * mid + B * math.sin(mid)) ** 2 < C ** 2:
        s = mid + 10 ** (-9)
    else:
        break
    
print(e)
