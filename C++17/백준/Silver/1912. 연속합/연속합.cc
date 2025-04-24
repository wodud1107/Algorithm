#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;

    int num[n];
    int dp[n];
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;

        num[i] = x;
    }

    dp[0] = num[0];
    int max_res = num[0];

    for (int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1] + num[i], num[i]);
        max_res = max(max_res, dp[i]);
    }

    cout << max_res << '\n';

    return 0;
}