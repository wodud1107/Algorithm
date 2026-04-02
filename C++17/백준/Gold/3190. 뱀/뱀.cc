#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int N, K, L;
int board[101][101];
int body[101][101];
pii curr_d = {0, 1};
int body_size = 1;

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

    queue<pii> q;
    q.push({1, 1});
    vector<pii> head_track;
    pii tail = {1, 1};
    int t = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        head_track.emplace_back(x, y);
        if (t > 0) {
            pii prev_tail = tail;
            tail = head_track[t - body_size + 1];
            if (prev_tail != tail) {
                body[prev_tail.first][prev_tail.second]--;
            }
        }
        body[x][y]++;

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

        if (1 > nx || nx > N || 1 > ny || ny > N || body[nx][ny] > 0) {
            cout << t;
            break;
        } else if (board[nx][ny] == 1) {
            board[nx][ny] = 0;
            body_size++;
        }
        q.emplace(nx, ny);
    }

    return 0;
}