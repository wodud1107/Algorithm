#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

struct Shark {
    int r, c;
    int s, d;
    int z;
};

int R, C, M;
int board[101][101];
vector<Shark> sharks;

pii dir[5] = {{}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(board, -1, sizeof(board));
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c] = i;
        sharks.push_back({r, c, s, d, z});
    }

    int answer = 0;
    for (int j = 1; j <= C; j++) {
        for (int i = 1; i <= R; i++) {
            int idx = board[i][j];
            if (idx != -1) {
                answer += sharks[idx].z;
                sharks[idx] = {-1, -1, 0, 0, 0};
                board[i][j] = -1;
                break;
            }
        }
        
        for (Shark& s : sharks) {    
            if (s.r == -1) continue;

            int sx = s.r, sy = s.c;
            auto [dx, dy] = dir[s.d];
            if (s.d <= 2) {
                int x = sx - 1;
                int cycle = 2 * (R - 1);

                x += dx * s.s;
                x = (x % cycle + cycle) % cycle;

                if (x > R - 1) {
                    x = cycle - x;
                    s.d ^= 3;
                }

                sx = x + 1;
            } else {
                int y = sy - 1;
                int cycle = 2 * (C - 1);

                y += dy * s.s;
                y = (y % cycle + cycle) % cycle;

                if (y > C - 1) {
                    y = cycle - y;
                    s.d ^= 7;
                }

                sy = y + 1;
            }
            
            s.r = sx;
            s.c = sy;
        }

        memset(board, -1, sizeof(board));
        for (int i = 0; i < sharks.size(); i++) {
            if (sharks[i].r == -1) continue;
            int r = sharks[i].r;
            int c = sharks[i].c;

            if (board[r][c] == -1) {
                board[r][c] = i;
            } else {
                int other = board[r][c];
                if (sharks[other].z > sharks[i].z) {
                    sharks[i] = {-1, -1, 0, 0, 0};
                } else {
                    sharks[other] = {-1, -1, 0, 0, 0};
                    board[r][c] = i;
                }
            }
        }
    }

    cout << answer << '\n';

    return 0;
}