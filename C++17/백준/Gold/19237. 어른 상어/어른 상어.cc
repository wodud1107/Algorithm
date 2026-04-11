#include <iostream>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

struct Shark {
    int r, c;
    int d;
};

int N, M, k;
int board[21][21];      // 상어 번호
Shark sharks[401];      // {r, c, 현재 방향}
pii smell[21][21];      // {상어 번호, 생성 시간}
int priority[401][5][4];   // 방향 우선순위 i: 상어 번호 j 방향 번호 k: 우선순위에 따른 방향

pii dirs[5] = {{}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> k;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0) {
                sharks[board[i][j]] = {i, j, 0};
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        cin >> sharks[i].d;
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 0; k < 4; k ++) {
                cin >> priority[i][j][k];
            }
        }
    }

    int t = 0;
    bool other_exist = false;
    while (1) {
        int only = 0;
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                if (smell[r][c].second + k == t) {
                    smell[r][c] = {-1, 1001};
                }

                if (board[r][c] > 0) only += board[r][c];
            }
        }
        if (only == 1) break;

        for (int i = 1; i <= M; i++) {
            auto [r, c, d] = sharks[i];
            if (r == -1) continue;
            smell[r][c] = {i, t};
        }

        t++;
        if (t > 1000) { other_exist = true; break; }

        memset(board, -1, sizeof(board));
        for (int i = 1; i <= M; i++) {
            auto [cx, cy, cd] = sharks[i];
            if (cx == -1) continue;
            
            bool moved = false;
            for (int p : priority[i][cd]) {
                auto [dx, dy] = dirs[p];
                int nx = cx + dx, ny = cy + dy;

                if (!(1 <= nx && nx <= N && 1 <= ny && ny <= N)) continue;

                if (smell[nx][ny].first > 0) continue;
                if (board[nx][ny] == -1) {
                    board[nx][ny] = i;
                    sharks[i] = {nx, ny, p};
                } else {
                    int other = board[nx][ny];
                    if (other > i) {
                        sharks[other] = {-1, -1, -1};
                        board[nx][ny] = i;
                        sharks[i] = {nx, ny, p};
                    } else {
                        sharks[i] = {-1, -1, -1};
                    }
                }
                moved = true;
                break;
            }

            if (moved) continue;

            for (int p : priority[i][cd]) {
                auto [dx, dy] = dirs[p];
                int nx = cx + dx, ny = cy + dy;

                if (!(1 <= nx && nx <= N && 1 <= ny && ny <= N)) continue;

                if (smell[nx][ny].first == i) {
                    if (board[nx][ny] == -1) {
                        board[nx][ny] = i;
                        sharks[i] = {nx, ny, p};
                    } else {
                        int other = board[nx][ny];
                        if (other > i) {
                            sharks[other] = {-1, -1, -1};
                            board[nx][ny] = i;
                            sharks[i] = {nx, ny, p};
                        } else {
                            sharks[i] = {-1, -1, -1};
                        }
                    }
                    moved = true;
                    break;
                }
            }
        }
    }

    if (other_exist) {
        cout << -1 << '\n';
    } else cout << t << '\n';

    return 0;
}