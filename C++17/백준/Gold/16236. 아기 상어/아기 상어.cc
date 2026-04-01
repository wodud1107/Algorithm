#include <iostream>
#include <string.h>
#include <vector>
#include <deque>
using namespace std;
using pii = pair<int, int>;

int N;
vector<vector<int>> board;
vector<pii> eat;

pii s_pos;
int s_size = 2;
int eat_cnt = 0;

deque<pii> q;
int visited[20][20];

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int answer = 0;

void find(vector<pii>& eat) {
    eat.clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0 && board[i][j] < s_size)
                eat.emplace_back(i, j);
        }
    }
}

void init_board(vector<vector<int>>& curr_board) {
    q = {s_pos};
    memset(visited, -1, sizeof(visited));
    visited[s_pos.first][s_pos.second] = 0;
    curr_board[s_pos.first][s_pos.second] = 0;
    find(eat);
}


void bfs() {
    init_board(board);

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();

        if (eat.empty()) break;

        int goal_x = -1, goal_y = -1;
        int min_time = N * N;
        for (const auto& [e_x, e_y] : eat) {
            if (visited[e_x][e_y] == -1) continue;
            if (min_time > visited[e_x][e_y]) {
                min_time = visited[e_x][e_y];
                goal_x = e_x;
                goal_y = e_y;
            }
        }

        if (goal_x == x && goal_y == y) {
            board[x][y] = 0;
            s_pos = {x, y};
            init_board(board);
            eat_cnt++;
            answer += min_time;
        }

        if (eat_cnt == s_size) {
            eat_cnt = 0;
            s_size++;
            find(eat);
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
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) s_pos = {i, j};
        }
    }

    bfs();
    cout << answer;

    return 0;
}