#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int R, C;
char board[1500][1500];
bool water_visited[1500][1500];
bool swan_visited[1500][1500];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    queue<pii> water_q, water_next_q;
    vector<pii> swans;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            
            if (board[i][j] != 'X') {
                water_q.push({i, j});
                water_visited[i][j] = true;
            }
            if (board[i][j] == 'L') {
                swans.push_back({i, j});
            }
        }
    }

    pii start = swans[0], end = swans[1];
    queue<pii> swan_q, swan_next_q;
    swan_q.push(start);
    swan_visited[start.first][start.second] = true;
    int day = 0;
    while (1) {
        bool meet = false;

        while (!swan_q.empty()) {
            auto [x, y] = swan_q.front();
            swan_q.pop();

            if (x == end.first && y == end.second) {
                meet = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx && nx < R && 0 <= ny && ny < C && !swan_visited[nx][ny]) {
                    swan_visited[nx][ny] = true;
                    
                    if (board[nx][ny] == 'X') {
                        swan_next_q.push({nx, ny});
                    } else {
                        swan_q.push({nx, ny});
                    }
                }
            }
        }

        if (meet) {
            cout << day << '\n';
            break;
        }

        while (!water_q.empty()) {
            auto [x, y] = water_q.front();
            water_q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx && nx < R && 0 <= ny && ny < C && !water_visited[nx][ny]) {
                    water_visited[nx][ny] = true;
                    if (board[nx][ny] == 'X') {
                        board[nx][ny] = '.';
                        water_next_q.push({nx, ny});
                    }
                }
            }
        }

        swan_q = swan_next_q;
        water_q = water_next_q;
        while (!swan_next_q.empty()) swan_next_q.pop();
        while (!water_next_q.empty()) water_next_q.pop();
        day++;
    }

    return 0;
}