#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int V, E;
vector<vector<int>> graph;
vector<int> color;

bool dfs(int cur, int c) {
    color[cur] = c;

    for (int nxt : graph[cur]) {
        if (color[nxt] == 0) {
            if (!dfs(nxt, -c)) return false;
        } else if (color[nxt] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;
    while (K--) {
        cin >> V >> E;
        graph.assign(V + 1, vector<int>());
        color.assign(V + 1, 0);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        bool ok = true;
        for (int i = 1; i <= V; i++) {
            if (color[i] == 0) {
                if (!dfs(i, 1)) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}