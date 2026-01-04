import sys
input = sys.stdin.readline

N = int(input())
ls = list(map(int, input().split()))
remove = int(input())

tr = [[] for _ in range(N)]
root = -1
    
for i in range(N):
    if ls[i] == -1:
        root = i
    else:
        if i != remove:
            tr[ls[i]].append(i)
        
if remove == root:
    print(0)
    exit(0)

count = 0
def dfs(node):
    global count
    
    if not tr[node]:
        count += 1
        return
    
    for child in tr[node]:
        dfs(child)
    
dfs(root)
print(count)