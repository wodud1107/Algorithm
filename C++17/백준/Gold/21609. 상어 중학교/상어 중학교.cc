#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

struct Group {
    int size;
    int rainbow;
    int r, c;
    vector<pii> blocks;
};

int N, M;
int board[21][21];

pii dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<Group> find_group() {
    int visited[21][21] = {};
    vector<Group> groups;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] <= 0) continue;
            if (visited[i][j]) continue;
            queue<pii> q;
            q.push({i, j});
            int lc_visited[21][21] = {};
            lc_visited[i][j] = 1;
            visited[i][j] = 1;
            int group_size = 0, rainbow_cnt = 0, first_r = i, first_c = j;
            vector<pii> blocks;
            while (!q.empty()) {
                auto [cx, cy] = q.front(); q.pop();
                blocks.push_back({cx, cy});
                group_size++;
                if (board[cx][cy] > 0) {
                    if (cx < first_r || (cx == first_r && cy < first_c)) {
                        first_r = cx;
                        first_c = cy;
                    }
                }

                for (int d = 0; d < 4; d++) {
                    auto [dx, dy] = dirs[d];
                    int nx = cx + dx, ny = cy + dy;

                    if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                        if (lc_visited[nx][ny]) continue;
                        if (board[nx][ny] == 0) {
                            lc_visited[nx][ny] = 1;
                            rainbow_cnt++;
                            q.push({nx, ny});
                        }
                        if (board[nx][ny] == board[i][j]) {
                            visited[nx][ny] = 1;
                            lc_visited[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            if (group_size >= 2) {
                groups.push_back({group_size, rainbow_cnt, first_r, first_c, blocks});
            }
        }
    }
    return groups;
}

int remove_blocks() {
    vector<Group> groups = find_group();
    int max_size = -1, max_rain_cnt = -1, max_r = -1, max_c = -1, idx = -1;
    for (int i = 0; i < groups.size(); i++) {
        if (max_size < groups[i].size) {
            max_size = groups[i].size;
            max_rain_cnt = groups[i].rainbow;
            max_r = groups[i].r;
            max_c = groups[i].c;
            idx = i;
        } else if (max_size == groups[i].size) {
            if (max_rain_cnt < groups[i].rainbow) {
                max_rain_cnt = groups[i].rainbow;
                max_r = groups[i].r;
                max_c = groups[i].c;
                idx = i;
            } else if (max_rain_cnt == groups[i].rainbow) {
                if (max_r < groups[i].r) {
                    max_r = groups[i].r;
                    max_c = groups[i].c;
                    idx = i;
                } else if (max_r == groups[i].r) {
                    if (max_c < groups[i].c) {
                        max_c = groups[i].c;
                        idx = i;
                    }
                }
            }
        }
    }

    if (idx == -1) return 0;
    for (auto [rx, ry] : groups[idx].blocks) {
        board[rx][ry] = -2;
    }
    return groups[idx].size * groups[idx].size;
}

void gravity() {
    for (int c = 1; c <= N; c++) {
        int bottom = N;
        for (int r = N; r >= 1; r--) {
            if (board[r][c] == -1) {
                bottom = r - 1;
            } else if (board[r][c] >= 0) {
                int val = board[r][c];
                board[r][c] = -2;
                board[bottom][c] = val;
                bottom--;
            }
        }
    }
}

void rotate(int copy_board[][21]) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            board[N - j + 1][i] = copy_board[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    while (1) {
        int point = remove_blocks();
        if (point == 0) break;
        answer += point;
        gravity();
        int temp[21][21];
        memcpy(temp, board, sizeof(board));
        rotate(temp);
        gravity();
    }

    cout << answer << '\n';

    return 0;
}