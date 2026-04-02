#include <iostream>
#include <cstring>
using namespace std;

int M, N;
int board[250000];
int dp[250000];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x) {
    if (x == (M * N -1)) return 1;
    if (dp[x] != -1) return dp[x];
    dp[x] = 0;
    
    for (int i = 0; i < 4; i++) {
        int nx = (x / N) + dx[i];
        int ny = (x % N) + dy[i];

        if (0 <= nx && nx < M && 0 <= ny && ny < N) {
            if (board[x] > board[nx * N + ny]) {
                dp[x] += dfs(nx * N + ny);
            }
        }
    }
    return dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i * N + j];
        }
    }
    memset(dp, -1, sizeof(dp));

    cout << dfs(0);

    return 0;
}