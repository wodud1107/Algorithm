#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int triangle[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cin >> triangle[i][j];
        }
    }

    int dp[n];
    fill(dp, dp + n, 0);
    dp[0] = triangle[0][0];
    for (int i = 1; i < n; i++){
        for (int j = i; j >= 0; j--){
            if (j == 0) dp[j] = dp[j] + triangle[i][j];
            else if (j == i) dp[j] = dp[j - 1] + triangle[i][j];
            else dp[j] = max(dp[j], dp[j - 1]) + triangle[i][j];
        }
    }

    int max_res = *max_element(dp, dp + n);

    cout << max_res << '\n';

    return 0;
}