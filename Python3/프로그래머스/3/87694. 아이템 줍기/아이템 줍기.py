from collections import deque

def solution(rectangle, characterX, characterY, itemX, itemY):
    board = [[-1] * 102 for _ in range(102)]
    for rect in rectangle:
        x1, y1, x2, y2 = map(lambda x: x * 2, rect)
        for x in range(x1, x2 + 1):
            for y in range(y1, y2 + 1):
                if x1 < x < x2 and y1 < y < y2:
                    board[x][y] = 0
                elif board[x][y] != 0:
                    board[x][y] = 1
                    
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    
    q = deque([(characterX * 2, characterY * 2, 0)])
    visited = [[False] * 102 for _ in range(102)]
    visited[characterX * 2][characterY * 2] = True
    
    while q:
        x, y, dist = q.popleft()
        
        if x == itemX * 2 and y == itemY * 2:
            return dist // 2
        
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            
            if 0 <= nx < 102 and 0 <= ny < 102:
                if visited[nx][ny]: continue
                if board[nx][ny] != 1: continue
                visited[nx][ny] = True
                q.append((nx, ny, dist + 1))