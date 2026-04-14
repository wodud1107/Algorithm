#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
using namespace std;

int N, M;
int board[1000][1000];

vector<int> cnt_map;
int mark = 2;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int cnt, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
            if (board[nx][ny] == 0) {
                board[nx][ny] = mark;
                cnt = dfs(cnt + 1, nx, ny);
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cnt_map.assign((N * M + 2), 0); 
    
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            board[i][j] = line[j] - '0';
        }
    }

    int print_board[1000][1000] = {};
    memcpy(print_board, board, sizeof(board));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                board[i][j] = mark;
                cnt_map[mark] = dfs(1, i, j);
                mark++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) {
                set<int> mark_set;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d], ny = j + dy[d];

                    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                        if (board[nx][ny] != 1) {
                            mark_set.insert(board[nx][ny]);
                        }
                    }
                }

                for (int m : mark_set) {
                    print_board[i][j] += cnt_map[m] % 10;
                }

                print_board[i][j] %= 10;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << print_board[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}