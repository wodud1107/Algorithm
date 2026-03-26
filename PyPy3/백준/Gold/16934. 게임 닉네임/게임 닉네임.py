import sys
input = sys.stdin.readline

N = int(input())
prefix = {}
word_count = {}

for _ in range(N):
    word = input().strip()
    word_count[word] = word_count.get(word, 0) + 1
    
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