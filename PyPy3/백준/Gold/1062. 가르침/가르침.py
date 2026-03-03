import sys
from itertools import combinations
input = sys.stdin.readline

N, K = map(int, input().split())

words = [input().rstrip() for _ in range(N)]

if K < 5: print(0); exit(0)
elif K == 26: print(N); exit(0)

learned = 0
for char in 'antic':
    learned |= (1 << (ord(char) - ord('a')))

word_masks = []
for word in words:
    mask = 0
    for char in word:
        mask |= (1 << (ord(char) - ord('a')))
    word_masks.append(mask)

remaining = [chr(i) for i in range(ord('a'), ord('z') + 1) if chr(i) not in 'antic']

max_cnt = 0
for combs in combinations(remaining, K - 5):
    current_learned = learned
    for char in combs:
        current_learned |= (1 << (ord(char) - ord('a')))
    
    count = 0
    for word_mask in word_masks:
        if (word_mask & current_learned) == word_mask:
            count += 1
            
    if count > max_cnt:
        max_cnt = count

print(max_cnt)