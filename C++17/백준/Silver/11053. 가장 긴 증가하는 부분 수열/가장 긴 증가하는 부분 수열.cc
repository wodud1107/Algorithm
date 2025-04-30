#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    int dp[N];
    for (int i = 0; i < N; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (A[j] < A[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp, dp + N) << '\n';

    return 0;
}