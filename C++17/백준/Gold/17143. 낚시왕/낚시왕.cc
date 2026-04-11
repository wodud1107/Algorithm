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

    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c] = z;
        sharks.push_back({r, c, s, d, z});
    }

    int answer = 0;
    for (int j = 1; j <= C; j++) {
        Shark target = {-1, -1, 0, 0, 0};

        bool search = false;
        for (Shark s : sharks) {
            if (s.z != 0) search = true; 
        }
        if (!search) break;
        for (int i = 1; i <= R; i++) {
            for (Shark& s : sharks) {
                if (target.z != 0) break;
                if (s.c == j && s.r == i) {
                    swap(target, s);
                    break;
                }
            }

            if (target.z != 0) { answer += target.z; break; }
        }
        
        for (Shark& s : sharks) {    
            if (s.r == -1) continue;

            int sx = s.r, sy = s.c;
            int should_go = s.s;
            if (s.d == 1 || s.d == 2) {
                should_go %= (2 * (R - 1));
            } else {
                should_go %= (2 * (C - 1));
            }
            while (should_go-- > 0) {
                auto [dx, dy] = dir[s.d];
                sx += dx; sy += dy;

                if (!(1 <= sx && sx <= R && 1 <= sy && sy <= C)) {
                    sx -= dx; sy -= dy;
                    should_go++;
                    switch (s.d) {
                    case 1: { s.d = 2; break; }
                    case 2: { s.d = 1; break; }
                    case 3: { s.d = 4; break; }
                    case 4: { s.d = 3; break; }
                    }
                }
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