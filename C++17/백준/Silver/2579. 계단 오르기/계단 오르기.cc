#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int point[301];
    for (int i = 0; i < N; i++){
        cin >> point[i];
    }

    int dp[301];
    dp[0] = point[0], dp[1] = point[0] + point[1], dp[2] = max(dp[0], point[1]) + point[2];
    for (int i = 3; i < N; i++){
        dp[i] = max(dp[i - 2], dp[i - 3] + point[i - 1]) + point[i];
    }

    cout << dp[N - 1] << '\n';

    return 0;
}