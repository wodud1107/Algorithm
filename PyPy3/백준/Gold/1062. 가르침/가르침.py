import sys
from itertools import combinations
input = sys.stdin.readline

N, K = map(int, input().split())

words = [input().rstrip() for _ in range(N)]

if K < 5: print(0); exit(0)
elif K == 26: print(N); exit(0)

learned = set(['a', 'n', 't', 'i', 'c'])
remaining = [chr(i) for i in range(ord('a'), ord('z') + 1) if chr(i) not in learned]

word_sets = []
for word in words:
    word_sets.append(set(word[4:-4]))
    
max_cnt = 0
for combs in combinations(remaining, K - 5):
    current_learned = learned.copy()
    
    for char in combs:
        current_learned.add(char)
        
    count = 0
    for w_set in word_sets:
        if w_set.issubset(current_learned):
            count += 1
    
    if count > max_cnt: max_cnt = count
    
print(max_cnt)