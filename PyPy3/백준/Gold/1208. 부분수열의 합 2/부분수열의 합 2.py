import sys
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

left_sums.sort()
right_sums.sort()

l_ptr = 0
r_ptr = len(right_sums) - 1
answer = 0
while l_ptr < len(left_sums) and r_ptr >= 0:
    l = left_sums[l_ptr]
    r = right_sums[r_ptr]
    curr_sum = l + r
    
    if curr_sum == S:
        l_cnt = 0
        r_cnt = 0
        
        while l_ptr < len(left_sums) and left_sums[l_ptr] == l:
            l_cnt += 1
            l_ptr += 1
            
        while r_ptr >= 0 and right_sums[r_ptr] == r:
            r_cnt += 1
            r_ptr -= 1
            
        answer += (l_cnt * r_cnt)
        
    elif curr_sum < S: l_ptr += 1
    else: r_ptr -= 1

if S == 0:
    answer -= 1

print(answer)