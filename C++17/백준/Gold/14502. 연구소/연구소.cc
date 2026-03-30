#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int N, M;
int board[8][8];
vector<pii> empties;
vector<pii> viruses;
int answer = 0;

void spread(int curr_board[8][8]) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    vector<pii> q = viruses;
    int front = 0;
    while (front < (int)q.size()) {
        auto [x, y] = q[front++];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M && curr_board[nx][ny] == 0) {
                curr_board[nx][ny] = 2;
                q.emplace_back(nx, ny);
            }
        }
    }
}

void dfs(int cnt, int start) {
    if (cnt == 3) {
        int spread_board[8][8];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                spread_board[i][j] = board[i][j];
            }
        }

        spread(spread_board);

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (spread_board[i][j]) continue;
                else cnt++;
            }
        }
        answer = answer > cnt ? answer : cnt;
        return;
    }

    for (int i = start; i < empties.size(); i++) {
        auto [x, y] = empties[i];
        if (board[x][y] != 0) continue;
        board[x][y] = 1;
        dfs(cnt + 1, i + 1);
        board[x][y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) empties.emplace_back(i, j);
            if (board[i][j] == 2) viruses.emplace_back(i, j);
        }
    }

    dfs(0, 0);
    cout << answer;

    return 0;
}