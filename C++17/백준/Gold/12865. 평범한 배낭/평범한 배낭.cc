#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int arr[N + 1][2];
    for (int i = 1; i <= N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    int dp[K + 1];
    fill(dp, dp + K + 1, 0);
    for (int i = 1; i <= N; i++){
        int W = arr[i][0];
        int V = arr[i][1];
        for (int j = K; j >= W; j--){
            dp[j] = max(dp[j], dp[j - W] + V);
        }
    }

    cout << dp[K] << '\n';

    return 0;
}