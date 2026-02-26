import sys
input = sys.stdin.readline

dice = list(map(int, input().split()))

class Node:
    def __init__(self, score):
        self.score = score
        self.next = None
        self.blue_next = None
     
board = [Node(i * 2) for i in range(21)]

end_node = Node(0)
for i in range(len(board) - 1):
    board[i].next = board[i + 1]
board[20].next = end_node
end_node.next = end_node
    
ls_25 = [Node(i) for i in range(25, 40, 5)]
ls_25[-1].next = board[-1]
for i in range(len(ls_25) - 1):
    ls_25[i].next = ls_25[i + 1]
    
def blue_arrow(ls):
    ls[-1].next = ls_25[0]
    
    for i in range(len(ls) - 1):
        ls[i].next = ls[i + 1]
    
ls_10 = [Node(i) for i in range(13, 20, 3)]
ls_20 = [Node(i) for i in range(22, 25, 2)]
ls_30 = [Node(i) for i in range(28, 25, -1)]
blue_arrow(ls_10)
blue_arrow(ls_20)
blue_arrow(ls_30)
board[5].blue_next = ls_10[0]
board[10].blue_next = ls_20[0]
board[15].blue_next = ls_30[0]

start_node = board[0]

def move(current, go):
    if current.blue_next:
        current = current.blue_next
        go -= 1
    
    while go > 0 and current != end_node:
        current = current.next
        go -= 1
        
    return current

pieces = [start_node, start_node, start_node, start_node]
def dfs(turn, current_score):
    if turn == 10:
        return current_score
    
    max_score = current_score
    for i in range(4):
        if pieces[i] in pieces[:i]:
            continue
        
        current_node = pieces[i]
        
        if current_node == end_node:
            continue
        
        next_node = move(current_node, dice[turn])
        
        if next_node != end_node and next_node in pieces:
            continue
        
        pieces[i] = next_node
        max_score = max(max_score, dfs(turn + 1, current_score + next_node.score))
        pieces[i] = current_node
    return max_score

print(dfs(0, 0))