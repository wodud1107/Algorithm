#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;
int N, M;
int S, D;

vector<int> dijkstra(const vector<vector<pii>>& graph, const vector<vector<bool>>& removed) {
    vector<int> dist(N, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty()) {
        auto [cost, curr] = pq.top();
        pq.pop();

        if (cost > dist[curr]) continue;

        for (int i = 0; i < graph[curr].size(); i++) {
            auto [nxt, w] = graph[curr][i];
            if (removed[curr][i]) continue;

            int nxt_cost = cost + w;
            if (dist[nxt] > nxt_cost) {
                dist[nxt] = nxt_cost;
                pq.push({nxt_cost, nxt});
            }
        }
    }

    return dist;
}

void remove_shortest_path(const vector<vector<pii>>& graph,
                          const vector<vector<pii>>& reversed_graph,
                          const vector<int>& dist,
                          vector<vector<bool>>& removed) {
    queue<int> q;
    vector<bool> visited(N, false);

    q.push(D);
    visited[D] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto [prev, w] : reversed_graph[curr]) {
            if (dist[prev] + w != dist[curr]) continue;

            for (int i = 0; i < graph[prev].size(); i++) {
                auto [nxt, cost] = graph[prev][i];
                if (nxt == curr && cost == w) {
                    removed[prev][i] = true;
                }
            }

            if (!visited[prev]) {
                visited[prev] = true;
                q.push(prev);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        cin >> S >> D;

        vector<vector<pii>> graph(N), reversed_graph(N);
        for (int i = 0; i < M; i++) {
            int U, V, P;
            cin >> U >> V >> P;
            graph[U].emplace_back(V, P);
            reversed_graph[V].emplace_back(U, P);
        }

        vector<vector<bool>> removed(N);
        for (int i = 0; i < N; i++) {
            removed[i].assign(graph[i].size(), false);
        }

        vector<int> dist = dijkstra(graph, removed);
        if (dist[D] == INF) {
            cout << -1 << '\n';
            continue;
        }

        remove_shortest_path(graph, reversed_graph, dist, removed);
        dist = dijkstra(graph, removed);
        if (dist[D] == INF) cout << -1 << '\n';
        else cout << dist[D] << '\n';
    }

    return 0;
}