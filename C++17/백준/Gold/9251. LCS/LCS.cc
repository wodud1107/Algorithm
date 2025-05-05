#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S1, S2;
    cin >> S1 >> S2;

    int dp[S1.length() + 1][S2.length() + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= S1.length(); i++){
        for (int j = 1; j <= S2.length(); j++){
            if (S1[i - 1] == S2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[S1.length()][S2.length()] << '\n';

    return 0;
}