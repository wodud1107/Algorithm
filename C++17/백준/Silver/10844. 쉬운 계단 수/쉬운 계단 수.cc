#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int dp[101][10];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < 10; i++){
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++){
        for (int j = 0; j < 10; j++){
            if (j > 0) dp[i][j] += dp[i - 1][j - 1];
            if (j < 9) dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= 1000000000;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 10; i++){
        cnt = (cnt + dp[N][i]) % 1000000000;
    }

    cout << cnt << '\n';

    return 0;
}