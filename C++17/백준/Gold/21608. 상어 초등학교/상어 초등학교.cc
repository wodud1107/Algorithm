#include <iostream>
using namespace std;
using pii = pair<int, int>;

int N;
int board[21][21];
int like[401][4];

pii dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void find_seat(int id) {
    int v[21][21] = {};
    int l[21][21] = {};
    int maximum = -1, r = -1, c = -1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] != 0) continue;

            int cnt = 0;
            int l_cnt = 0;
            for (int d = 0; d < 4; d++) {
                auto [dx, dy] = dirs[d];
                int nx = i + dx, ny = j + dy;

                if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                    if (board[nx][ny] == 0) cnt++;
                    for (int k = 0; k < 4; k++) {
                        if (board[nx][ny] == like[id][k]) l_cnt++;
                    }
                }
            }
            v[i][j] = cnt;
            l[i][j] = l_cnt;

            if (maximum < l_cnt) {
                maximum = l_cnt; r = i; c = j;
            }
            else if (maximum == l_cnt) {
                if (v[i][j] > v[r][c]) { r = i; c = j; }
                else if (v[i][j] == v[r][c]) {
                    if (i < r) { r = i; c = j;}
                    else if (i == r) {
                        if (j < c) c = j;
                    }
                }
            }
        }
    }
    board[r][c] = id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N * N; i++) {
        int id;
        cin >> id;
        for (int j = 0; j < 4; j++) {
            cin >> like[id][j];
        }
        find_seat(id);
    }

    int satisfy[5] = {0, 1, 10, 100, 1000};
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int std = board[i][j];
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                auto [dx, dy] = dirs[d];
                int nx = i + dx, ny = j + dy;

                if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                    for (int k = 0; k < 4; k++) {
                        if (board[nx][ny] == like[std][k]) cnt++;
                    }
                }
            }
            answer += satisfy[cnt];
        }
    }

    cout << answer << '\n';

    return 0;
}