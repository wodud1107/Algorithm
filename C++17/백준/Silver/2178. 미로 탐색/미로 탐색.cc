#include <iostream>
#include <string>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int N, M;
int board[101][101];
int visited[101][101];
int answer = 10000;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 1; j <= M; j++) {
            board[i][j] = line[j - 1] - '0';
            visited[i][j] = -1;
        }
    }

    queue<pii> q;
    q.emplace(1, 1);
    visited[1][1] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == N && y == M) {
            if (answer > visited[x][y])
                answer = visited[x][y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (1 <= nx && nx <= N && 1 <= ny && ny <= M && visited[nx][ny] == -1) {
                if (board[nx][ny] == 1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    cout << answer;

    return 0;
}