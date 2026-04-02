#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int seq[2001];
    for (int i = 1; i <= N; i++){
        cin >> seq[i];
    }
    int M;
    cin >> M;
    bool dp[2001][2001] = { false };
    dp[N][N] = true;
    for (int i = 1; i < N; i++) {
        dp[i][i] = true;
        if (seq[i] == seq[i + 1]) {
            dp[i][i + 1] = true;
        }
    }

    for (int len = 3; len <= N; len++) {
        for (int i = 1; i + len - 1 <= N; i++) {
            int j = i + len - 1;
            if (seq[i] == seq[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    while (M--) {
        int S, E;
        cin >> S >> E;

        cout << dp[S][E] << '\n';
    }

    return 0;
}