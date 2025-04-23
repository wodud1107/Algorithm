#include <iostream>
using namespace std;

long long dp[101];

void P(){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= 100; i++){
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    P();

    while (T--){
        int N;
        cin >> N;

        cout << dp[N] << '\n';
    }

    return 0;
}