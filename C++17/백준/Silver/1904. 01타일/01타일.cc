#include <iostream>
using namespace std;

int dp[1000001];
int tile(int n){
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    cout << tile(N) << '\n';

    return 0;
}