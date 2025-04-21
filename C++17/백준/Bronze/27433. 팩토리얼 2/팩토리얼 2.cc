#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    long long dp[21];
    fill(dp, dp + 21, 1);
    for (int i = 1; i <= N; i++){
        dp[i] = dp[i - 1] * i;
    }

    cout << dp[N] << '\n';
    
    return 0;
}