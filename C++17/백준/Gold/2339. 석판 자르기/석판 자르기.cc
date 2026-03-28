#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N;
vector<vector<int>> board;

int cut(const vector<vector<int>>& board, const vector<pii>& dirts, const vector<pii>& jewelry, bool dir) {
    int dirt_cnt = dirts.size(), jewel_cnt = jewelry.size();
    if (jewel_cnt == 1 && dirt_cnt == 0) return 1;
    if (jewel_cnt != dirt_cnt + 1) return 0;

    int r_size = board.size();
    int c_size = board[0].size();
    int total_cnt = 0;
    if (dir) {
        for (const auto& [i, _]: dirts) {
            if (i == 0 or i == r_size - 1) continue;
            if (binary_search(board[i].begin(), board[i].end(), 2)) continue;

            vector<vector<int>> up(i, vector<int>(c_size, 0));
            vector<pii> up_dirts;
            vector<pii> up_jewelry;
            for (int r = 0; r < i; r++) {
                for (int c = 0; c < c_size; c++) {
                    if (board[r][c] == 1) up_dirts.push_back({ r, c });
                    if (board[r][c] == 2) up_jewelry.push_back({ r, c });
                    up[r][c] = board[r][c];
                }
            }
            int res1 = cut(up, up_dirts, up_jewelry, false);
            if (res1 == 0) continue;

            vector<vector<int>> down(r_size - i - 1, vector<int>(c_size, 0));
            vector<pii> down_dirts;
            vector<pii> down_jewelry;
            for (int r = 0; r < r_size - i - 1; r++) {
                for (int c = 0; c < c_size; c++) {
                    if (board[r + i + 1][c] == 1) down_dirts.push_back({ r, c });
                    if (board[r + i + 1][c] == 2) down_jewelry.push_back({ r, c });
                    down[r][c] = board[r + i + 1][c];
                }
            }
            int res2 = cut(down, down_dirts, down_jewelry, false);
            if (res2 == 0) continue;

            total_cnt += res1 * res2;
        }
    }
    else {
        for (const auto& [_, j]: dirts) {
            if (j == 0 or j == c_size - 1) continue;
            bool can_cut = true;
            for (int r = 0; r < r_size; r++) {
                if (board[r][j] == 2) can_cut = false;
            }

            if (can_cut) {
                vector<vector<int>> left(r_size, vector<int>(j, 0));
                vector<pii> left_dirts;
                vector<pii> left_jewelry;
                for (int r = 0; r < r_size; r++) {
                    for (int c = 0; c < j; c++) {
                        if (board[r][c] == 1) left_dirts.push_back({ r, c });
                        if (board[r][c] == 2) left_jewelry.push_back({ r, c });
                        left[r][c] = board[r][c];
                    }
                }
                int res1 = cut(left, left_dirts, left_jewelry, true);
                if (res1 == 0) continue;
                
                vector<vector<int>> right(r_size, vector<int>(c_size - j - 1, 0));
                vector<pii> right_dirts;
                vector<pii> right_jewelry;
                for (int r = 0; r < r_size; r++) {
                    for (int c = 0; c < c_size - j - 1; c++) {
                        if (board[r][c + j + 1] == 1) right_dirts.push_back({ r, c });
                        if (board[r][c + j + 1] == 2) right_jewelry.push_back({ r, c });
                        right[r][c] = board[r][c + j + 1];
                    }
                }
                int res2 = cut(right, right_dirts, right_jewelry, true);
                if (res2 == 0) continue;
                
                total_cnt += res1 * res2;
            }
        }
    }

    return total_cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    board.resize(N, vector<int>(N));

    vector<pii> dirts;
    vector<pii> jewelry;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a; cin >> a;
            if (a == 1) dirts.push_back({ i, j });
            if (a == 2) jewelry.push_back({ i, j });
            board[i][j] = a;
        }
    }

    int answer = cut(board, dirts, jewelry, true) + cut(board, dirts, jewelry, false);
    if (!answer) answer = -1;
    cout << answer;

    return 0;
}