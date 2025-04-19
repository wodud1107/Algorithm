#include <iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    int dp[11];
    fill(dp, dp + 11, 1);
    for(int i = 1; i < 11; i++){
        dp[i] = dp[i - 1] * i;
    }

    cout << dp[N] / (dp[K] * dp[N - K]) << '\n';

    return 0;
}