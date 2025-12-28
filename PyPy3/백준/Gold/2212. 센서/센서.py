import sys
input = sys.stdin.readline

N = int(input())
K = int(input())

ls = list(map(int, input().split()))
    
ls.sort()
    
diff = []
for i in range(N - 1):
    diff.append(ls[i + 1] - ls[i])

diff.sort()    
print(sum(diff[:N - K]))