#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> tree;
    tree.push_back(0);
    for (int i = 0; i < n; i++) {
        int boss;
        cin >> boss;
        tree.push_back(boss);
    }

    vector<int> dp;
    for (int i = 0; i <= n; i++) {
        dp.push_back(0);
    }

    for (int i = 0; i < m; i++) {
        int who, value;
        cin >> who >> value;

        dp[who] += value;
    }

    for (int i = 2; i <= n; i++) {
        dp[i] += dp[tree[i]];
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << ' ';
    }
}