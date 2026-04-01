#include <iostream>
#include <string.h>
#include <deque>
using namespace std;
using pii = pair<int, int>;

int N;
int board[20][20];
int visited[20][20];

pii s_pos;
int s_size = 2;
int eat_cnt = 0;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int answer = 0;

bool bfs() {
    memset(visited, -1, sizeof(visited));
    deque<pii> q;
    q.push_back(s_pos);
    visited[s_pos.first][s_pos.second] = 0;

    int min_time = -1;
    int goal_x = -1, goal_y = -1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();

        if (min_time != -1 && visited[x][y] > min_time) break;

        if (board[x][y] != 0 && board[x][y] < s_size) {
            if (min_time == -1) {
                min_time = visited[x][y];
                goal_x = x;
                goal_y = y;
            }
            else {
                if (x < goal_x || (x == goal_x && y < goal_y)) {
                    goal_x = x;
                    goal_y = y;
                }
            }
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (visited[nx][ny] == -1) {
                    if (s_size < board[nx][ny]) continue;

                    visited[nx][ny] = visited[x][y] + 1;
                    q.emplace_back(nx, ny);
                }
            }
        }
    }

    if (goal_x == -1) return false;
    answer += min_time;
    eat_cnt++;
    board[goal_x][goal_y] = 0;
    s_pos = {goal_x, goal_y};

    if (eat_cnt == s_size) {
        eat_cnt = 0;
        s_size++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                s_pos = {i, j};
                board[i][j] = 0;
            }
        }
    }

    while (bfs()) {}
    cout << answer;

    return 0;
}