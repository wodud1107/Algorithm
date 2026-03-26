import sys
input = sys.stdin.readline

N = int(input())
prefix = {}
word_count = {}

for _ in range(N):
    word = input().strip()
    
    if word in word_count:
        word_count[word] += 1
    else: word_count[word] = 1
    
    current = prefix
    alias = ""
    found_alias = False
    
    for char in word:
        if not found_alias:
            alias += char
            
        if char not in current:
            current[char] = {}
            found_alias = True
        
        current = current[char]
    
    if not found_alias:
        alias = word
        if word_count[word] > 1:
            alias += str(word_count[word])
    
    print(alias)