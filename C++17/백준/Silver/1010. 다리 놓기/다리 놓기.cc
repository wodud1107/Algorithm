#include <iostream>
using namespace std;

int main(){
    int T; cin >> T;

    long long dp[31][31];
    for (int i = 0; i < 31; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0 || i == j) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    while (T--){
        int N, M;
        cin >> N >> M;

        cout << dp[M][N] << '\n';
    }

    return 0;
}