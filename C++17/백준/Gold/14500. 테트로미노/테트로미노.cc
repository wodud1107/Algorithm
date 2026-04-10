#include <iostream>
using namespace std;

int N, M;
int board[500][500];
int visited[500][500];
int max_val = 0;
int answer = 0;
pair<int, int> dir[4] =  {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int cnt, int sum, int x, int y) {
    if (sum + (4 - cnt) * max_val <= answer) return;

    if (cnt == 4) {
        answer = answer < sum ? sum : answer; 
        return;
    }

    for (auto [dx, dy] : dir) {
        int nx = x + dx, ny = y + dy;

        if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny]) {
            if (cnt == 2) {
                visited[nx][ny] = 1;
                dfs(cnt + 1, sum + board[nx][ny], x, y);
                visited[nx][ny] = 0;
            }
            visited[nx][ny] = 1;
            dfs(cnt + 1, sum + board[nx][ny], nx, ny);
            visited[nx][ny] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            max_val = max_val < board[i][j] ? board[i][j] : max_val;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 1;
            dfs(1, board[i][j], i, j);
            visited[i][j] = 0;
        }
    }

    cout << answer;

    return 0;
}