#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int dp[N + 1];
    dp[1] = 0;
    for (int i = 2; i <= N; i++){
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
        if (i % 3 == 0) dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
        if (i % 6 == 0) dp[i] = min(dp[i - 1], min(dp[i /2], dp[i / 3])) + 1;
    }

    cout << dp[N] << '\n';

    return 0;
}