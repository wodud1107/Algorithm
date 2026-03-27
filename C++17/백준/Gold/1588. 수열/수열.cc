#include <iostream>
using ll = long long;
using namespace std;

const int rules[4][3] = { {}, {1, 3, 2}, {2, 1, 1}, {2, 3, 2}};
int init, N;
ll L, R;

ll dp[21][4][3];
ll answer[3];

void get_counts(int num, int time, ll start, ll end) {
    if (end < L || start > R) {
        return;
    }

    if (L <= start && end <= R) {
        for (int i = 0; i < 3; i++)
            answer[i] += dp[time][num][i];
        return;
    }

    ll step = (end - start + 1) / 3;
    ll curr_start = start;
    for (const auto& nxt_num: rules[num]) {
        get_counts(nxt_num, time - 1, curr_start, curr_start + step - 1);
        curr_start += step;
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> init >> L >> R >> N;

    for (int i = 1; i < 4; i++) {
        dp[0][i][i - 1] = 1;
    }

    for (int t = 1; t <= N; t++) {
        for (int num = 1; num < 4; num ++) {
            const auto& r = rules[num];
            for (int i = 0; i < 3; i++) {
                dp[t][num][i] = dp[t - 1][r[0]][i] + dp[t - 1][r[1]][i] + dp[t - 1][r[2]][i];
            }
        }
    }

    ll total_len = dp[N][init][0] + dp[N][init][1] + dp[N][init][2];
    get_counts(init, N, 0, total_len - 1);
    for (int i = 0; i < 3; i++)
        cout << answer[i] << ' ';

    return 0;
}