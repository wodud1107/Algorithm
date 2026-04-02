#include <iostream>
#include <string>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int N, M;
int board[100][100];
int visited[100][100];
int answer = 10000;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            board[i][j] = line[j] - '0';
            visited[i][j] = -1;
        }
    }

    queue<pii> q;
    q.emplace(0, 0);
    visited[0][0] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny] == -1) {
                if (board[nx][ny] == 1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    cout <<visited[N - 1][M - 1];

    return 0;
}