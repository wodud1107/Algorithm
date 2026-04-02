#include <iostream>
#include <cstring>
using namespace std;

int M, N;
int board[500][500];
int dp[500][500];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    if (x == M - 1 && y == N -1) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < M && 0 <= ny && ny < N) {
            if (board[x][y] > board[nx][ny]) {
                dp[x][y] += dfs(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0);

    return 0;
}