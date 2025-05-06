#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int W[N], V[N];
    for (int i = 0; i < N; i++){
        cin >> W[i] >> V[i];
    }

    int dp[N + 1][K + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= K; j++){
            if (W[i - 1] <= j) dp[i][j] = max(dp[i - 1][j], V[i - 1] + dp[i - 1][j - W[i - 1]]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}