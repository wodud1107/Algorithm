import sys
input = sys.stdin.readline

N = int(input())
prefixes = set()
word_count = {}

for _ in range(N):
    word = input().strip()
    
    if word in word_count:
        word_count[word] += 1
    else: word_count[word] = 1
    
    alias = ""
    found_alias = False
    
    for i in range(1, len(word) + 1):
        prefix = word[:i]
        
        if not found_alias and prefix not in prefixes:
            alias = prefix
            found_alias = True
        
        prefixes.add(prefix)    

    if not found_alias:
        alias = word
        if word_count[word] > 1:
            alias += str(word_count[word])
    
    print(alias)