import sys
input = sys.stdin.readline

L, K, C = map(int, input().split())
pos = list(map(int, input().split()))
pos.append(0)
pos.append(L)
sorted_cut = sorted(list(set(pos)))

def check(size):
    last_cut = L
    cut = C
    for i in range(len(sorted_cut) - 2, -1, -1):
        if (sorted_cut[i + 1] - sorted_cut[i] > size):
            return -1
        if (last_cut - sorted_cut[i] > size):
            cut -= 1
            last_cut = sorted_cut[i + 1]
            if (cut < 0): return -1
    if (cut > 0):
        return sorted_cut[1]
    return last_cut

s, e = 1, L
maximum = L
while (s <= e):
    mid = (s + e) // 2

    if (check(mid) > 0):
        maximum = mid
        e = mid - 1
    else: s = mid + 1

print(maximum, check(maximum))