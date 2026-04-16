#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    ll liquid[5001];
    for (int i = 0; i < N; i++) {
        cin >> liquid[i];
    }

    sort(liquid, liquid + N);

    ll minimum = 1e12;
    ll answer[3];
    for (int i = 0; i < N - 2; i++) {
        int l = i + 1, r = N - 1;
        while (l < r) {
            ll S = liquid[i] + liquid[l] + liquid[r];

            if (abs(S) < minimum) {
                minimum = abs(S);
                answer[0] = liquid[i];
                answer[1] = liquid[l];
                answer[2] = liquid[r];
            }

            if (S < 0) l += 1;
            else r -= 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}