#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<vector<int>> tree;

void dfs(int node, int parent, vector<array<ll, 3>>& dp) {
    for (int nxt : tree[node]) {
        if (nxt == parent) continue;
        dfs(nxt, node, dp);
        dp[node][0] += max(dp[nxt][1], dp[nxt][2]);
        dp[node][1] += max(dp[nxt][0], dp[nxt][2]);
        dp[node][2] += max(dp[nxt][0], dp[nxt][1]);
    }
}

void trace(int node, int parent, vector<array<ll, 3>>& dp, vector<int>& colors) {
    int parent_color = colors[node];

    for (int nxt : tree[node]) {
        if (nxt == parent) continue;
        int best_color = -1;
        int max_val = -1;

        for (int i = 0; i < 3; i++) {
            if (i == parent_color) continue;
            if (dp[nxt][i] > max_val) {
                max_val = dp[nxt][i];
                best_color = i;
            }
        }
        colors[nxt] = best_color;
        trace(nxt, node, dp, colors);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    tree.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<array<ll, 3>> light(N + 1), dp(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            int c; cin >> c;
            light[i][j] = c;
        }
    }

    dp = light;
    dfs(1, 0, dp);

    vector<int> colors(N + 1);
    int root_color = 0;
    for (int i = 1; i < 3; i++) {
        if (dp[1][i] > dp[1][root_color]) root_color = i;
    }
    colors[1] = root_color;
    trace(1, 0, dp, colors);

    cout << max({dp[1][0], dp[1][1], dp[1][2]}) << '\n';
    char color_map[3] = {'R', 'G', 'B'};
    for (int i = 1; i <= N; i++) {
        cout << color_map[colors[i]];
    }

    return 0;
}