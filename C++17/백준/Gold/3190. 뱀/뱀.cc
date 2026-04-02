#include <iostream>
#include <deque>
using namespace std;
using pii = pair<int, int>;

int N, K, L;
int board[101][101];
pii curr_d = {0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }
    cin >> L;
    char dirs[10000];
    for (int i = 0; i < L; i++) {
        int t;
        char d;
        cin >> t >> d;
        dirs[t] = d;
    }

    deque<pii> q;
    q.emplace_back(1, 1);
    board[1][1] = 2;
    int t = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        board[x][y] = 2;

        int nx = x + curr_d.first;
        int ny = y + curr_d.second;
        t++;
        if (dirs[t] == 'L') {
            if (curr_d.first == 1) {
                curr_d = {0, 1};
            } else if (curr_d.first == -1) {
                curr_d = {0, -1};
            } else if (curr_d.second == 1) {
                curr_d = {-1, 0};
            } else if (curr_d.second == -1) {
                curr_d = {1, 0};
            }
        } else if (dirs[t] == 'D') {
            if (curr_d.first == 1) {
                curr_d = {0, -1};
            } else if (curr_d.first == -1) {
                curr_d = {0, 1};
            } else if (curr_d.second == 1) {
                curr_d = {1, 0};
            } else if (curr_d.second == -1) {
                curr_d = {-1, 0};
            }
        }

        if (1 > nx || nx > N || 1 > ny || ny > N || board[nx][ny] == 2) {
            cout << t;
            break;
        } else if (board[nx][ny] == 0) {
            auto [tx, ty] = q.back();
            q.pop_back();
            board[tx][ty] = 0;
        } else if (board[nx][ny] == 1) {
            board[nx][ny] = 0;
        }
        q.emplace_front(nx, ny);
    }

    return 0;
}