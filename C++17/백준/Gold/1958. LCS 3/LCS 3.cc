#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int dp[2][101][101] = { 0 };
    
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            for (int k = 1; k <= s3.size(); k++) {
                char c1 = s1[i - 1];
                char c2 = s2[j - 1];
                char c3 = s3[k - 1];

                if (c1 == c2 && c2 == c3)
                    dp[i % 2][j][k] = dp[(i - 1) % 2][j - 1][k - 1] + 1;
                else
                    dp[i % 2][j][k] = max(dp[(i - 1) % 2][j][k], max(dp[i % 2][j - 1][k], dp[i % 2][j][k - 1]));
            }
        }
    }

    cout << dp[s1.size() % 2][s2.size()][s3.size()];

    return 0;
}