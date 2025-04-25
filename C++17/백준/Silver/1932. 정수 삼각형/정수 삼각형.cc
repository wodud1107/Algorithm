#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int triangle[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            int x; cin >> x;

            triangle[i][j] = x;
        }
    }

    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        }
    }

    int max_res = INT_MIN;
    for (int i = 0; i < n; i++){
        max_res = max(max_res, dp[n - 1][i]);
    }

    cout << max_res << '\n';

    return 0;
}