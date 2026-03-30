#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, M;
vector<vector<int>> board;
vector<pii> walls;
vector<pii> viruses;
int answer = 0;

vector<vector<int>> spread(vector<vector<int>>& curr_board) {
    queue<pii> q(deque<pii>(viruses.begin(), viruses.end()));

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M && curr_board[nx][ny] == 0) {
                curr_board[nx][ny] = 2;
                q.emplace(nx, ny);
            }
        }
    }

    return curr_board;
}

void dfs(int cnt, vector<vector<int>>& curr_board) {
    if (cnt == 3) {
        vector<vector<int>> spread_board = curr_board;
        spread(spread_board);

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (spread_board[i][j] == 0) cnt++;
            }
        }
        answer = max(answer, cnt);
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (curr_board[i][j] == 0) {
                curr_board[i][j] = 1;
                dfs(cnt + 1, curr_board);
                curr_board[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    board.resize(N, vector<int>(M, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) walls.emplace_back(i, j);
            if (board[i][j] == 2) viruses.emplace_back(i, j);
        }
    }

    dfs(0, board);
    cout << answer;

    return 0;
}