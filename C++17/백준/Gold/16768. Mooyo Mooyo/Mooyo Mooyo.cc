#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int N, K;
int board[100][10];
vector<vector<bool>> visited;
vector<pii> connected;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int num, int x, int y) {
    visited[x][y] = true;
    connected.emplace_back(x, y);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < N && 0 <= ny && ny < 10 && !visited[nx][ny] && board[nx][ny] == num) {
            dfs(num, nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        char line[11];
        cin >> line;
        for (int j = 0; j < 10; j++) {
            board[i][j] = line[j] - '0';
        }
    }

    while (1) {
        visited.assign(N, vector<bool>(10, false));
        vector<pii> removable;
        bool found = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] == 0 || visited[i][j]) continue;
                dfs(board[i][j], i, j);
                if (connected.size() >= K) {
                    removable.insert(removable.end(), connected.begin(), connected.end());
                    found = true;
                }
                connected.clear();
            }
        }

        if (!found) break;

        for (auto [x, y] : removable) {
            board[x][y] = 0;
        }

        for (int j = 0; j < 10; j++) {
            vector<int> stack;
            for (int i = 0; i < N; i++) {
                if (board[i][j] != 0) stack.push_back(board[i][j]);
            }

            for (int i = N - 1; i > -1; i--) {
                if (stack.empty()) board[i][j] = 0;
                else {
                    board[i][j] = stack.back();
                    stack.pop_back();
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}