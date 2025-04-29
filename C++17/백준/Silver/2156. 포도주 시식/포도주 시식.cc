#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int wine[n];
    for (int i =0; i < n; i++){
        cin >> wine[i];
    }

    int dp[n];
    dp[0] = wine[0], dp[1] = wine[0] + wine[1], dp[2] = max(wine[0] + wine[2], max(wine[1] + wine[2], wine[0] + wine[1]));
    for (int i = 3; i < n; i++){
        dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], max(dp[i - 2] + wine[i], dp[i - 1]));
    }

    cout << dp[n - 1] << '\n';

    return 0;
}