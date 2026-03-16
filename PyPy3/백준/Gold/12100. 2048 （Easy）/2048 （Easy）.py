import sys
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

def rotate_board(cnt, board):
    temp_board = [row[:] for row in board]
    for _ in range(cnt):
        rotated = [[0] * N for _ in range(N)]
        for i in range(N):
            for j in range(N):
                rotated[j][N - 1 - i] = temp_board[i][j]
        temp_board = rotated
        
    return temp_board

def move(dir, board):
    rotated = rotate_board(dir, board)
    temp_board = [[0] * N for _ in range(N)]
    
    for i in range(N):
        nums = []
        for j in range(N - 1, -1, -1):
            if rotated[i][j] != 0:
                nums.append(rotated[i][j])
        
        merged = []
        idx = 0
        while idx < len(nums):
            if idx + 1 < len(nums) and nums[idx] == nums[idx + 1]:
                merged.append(nums[idx] * 2)
                idx += 2
            else:
                merged.append(nums[idx])
                idx += 1
        
        while len(merged) < N:
            merged.append(0)
            
        temp_board[i] = merged
            
    return temp_board

def dfs(board, cnt, val):
    if (cnt == 5):
        return val
    
    dir = [0, 1, 2, 3]
    for d in dir:
        temp_board = [row[:] for row in board]
        temp_board = move(d, temp_board)
        cur_max = max(map(max, temp_board))
        val = dfs(temp_board, cnt + 1, max(val, cur_max))
    return val

print(dfs(board, 0, 0))