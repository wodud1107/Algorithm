#include <iostream>
using namespace std;

int dp[41];

void fibonacci(int n){
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++){
        dp[i] = dp[i - 2] + dp[i - 1];
    }
}

int main(){
    int n;
    cin >> n;

    fibonacci(n);
    cout << dp[n] << ' ' << n-2 << '\n';

    return 0;
}