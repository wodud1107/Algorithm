import sys
from itertools import combinations
input = sys.stdin.readline

'''
N 개 세로 M 개 가로
세로선 마다 H 개 가로
사다리 게임 규칙대로 내려오면서 만나면 옆 세로선으로 이동
2 <= N <= 10, 1 <= H <= 30, 0 <= M <= (N-1) * H

M 개의 가로선 정보
(a, b) b <-> b + 1 세로선끼리 연결 1 <= a <= H 위치에서

i 번 세로선 결과가 i 가 나오게 하는 추가해야할 최소 가로선 개수 3보다 크거나 불가능하면 -1

2차원 배열을 생성해서 각 행에 숫자를 매겨서 세로선 넘버링
가로선 연결되면 세로선 번호를 크로스

배열에 저장된 값을 통해서
연결된 번호 열로 이동해서 내려가는 down 함수

브루트포스로 가로선이 2개 연장되지 않도록 체크해서 진행
'''

N, M, H = map(int, input().split())

if M == 0: print(0); exit(0)

ladders = [[i for i in range(N + 1)] for _ in range(H + 1)]
def make_row(ladders, a, b):
    ladders[a][b] = b + 1
    ladders[a][b + 1] = b

row = set()
for _ in range(M):
    (a, b) = map(int, input().split())
    row.add((a, b))
    if b - 1 > 0: row.add((a, b - 1))
    elif b + 1 < N: row.add((a, b + 1))
    make_row(ladders, a, b)
    
remaining = [(a, b) for b in range(1, N) for a in range(1, H + 1) if (a, b) not in row]

def down(ladders, i):
    current = i
    for r in range(1, H + 1):
        current = ladders[r][current]
        
    if current == i: return True
    return False

def check_all_down(ladders):
    for n in range(1, N + 1):
        if not down(ladders, n):
            return False

    return True

for count in range(4):
    for rows in combinations(remaining, count):
        temp_ladders = [row[:] for row in ladders]
        temp_row = row.copy()
        for add_row in rows:
            if add_row[1] - 1 > 0: temp_row.add((add_row[0], add_row[1] - 1))
            elif add_row[1] + 1 < N: temp_row.add((add_row[0], add_row[1] + 1))
            
            if add_row not in temp_row:
                make_row(temp_ladders, add_row[0], add_row[1])
        
        if check_all_down(temp_ladders): print(count); exit(0)
        
print(-1)