#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int temp[N + 1];
    fill(temp, temp + N + 1, 0);
    for (int i = 1; i <= N; i++){
        int x;
        cin >> x;

        temp[i] = temp[i - 1] + x;
    }

    int res = INT_MIN;
    for (int i = 0; i <= N - K; i++){
        res = max(res, temp[i + K] - temp[i]);
    }
    
    cout << res << '\n';

    return 0;
}