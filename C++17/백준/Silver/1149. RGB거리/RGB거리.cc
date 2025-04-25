#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int dp[N][3];
    int R, G, B;
    cin >> R >> G >> B;
    dp[0][0] = R, dp[0][1] = G, dp[0][2] = B;

    for (int i = 1; i < N; i++){
        cin >> R >> G >> B;

        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B;
    }

    cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2])) << '\n';

    return 0;
}