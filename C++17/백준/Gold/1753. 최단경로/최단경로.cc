#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;
    vector<vector<pii>> graph(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> dist(V + 1, 1e9);
    dist[K] = 0;
    pq.push({0, K});
    while (!pq.empty()) {
        auto [weight, curr] = pq.top(); pq.pop();

        if (weight > dist[curr]) continue;

        for (auto [nxt, w] : graph[curr]) {
            int nxt_w = weight + w;
            if (dist[nxt] > nxt_w) {
                dist[nxt] = nxt_w;
                pq.push({nxt_w, nxt});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == 1e9) {
            cout << "INF" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}