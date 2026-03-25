import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline

N, S = map(int, input().split())
nums = list(map(int, input().split()))

lefts = nums[:N // 2]
rights = nums[N // 2:]

def get_subset_sums(arr):
    sums = [0]
    for n in arr:
        sums += [s + n for s in sums]
    return sums

left_sums = get_subset_sums(lefts)
right_sums = get_subset_sums(rights)

right_sums.sort()

answer = 0
for l_sum in left_sums:
    target = S - l_sum
    count = bisect_right(right_sums, target) - bisect_left(right_sums, target)
    answer += count

if S == 0:
    answer -= 1

print(answer)