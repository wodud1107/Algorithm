#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<vector<int>> station(N + 1);
    vector<int> degree(N + 1);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        station[a].push_back(b);
        station[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    vector<bool> is_cycle(N + 1, true);
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 1) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        is_cycle[cur] = false;

        for (int next : station[cur]) {
            degree[next]--;
            if (degree[next] == 1) q.push(next);
        }
    }

    vector<int> dist(N + 1, -1);
    queue<int> dist_q;
    for (int i = 1; i <= N; i++) {
        if (is_cycle[i]) {
            dist[i] = 0;
            dist_q.push(i);
        }
    }

    while (!dist_q.empty()) {
        int cur = dist_q.front();
        dist_q.pop();

        for (int next : station[cur]) {
            if (dist[next] != -1) continue;
            dist[next] = dist[cur] + 1;
            dist_q.push(next);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << dist[i] << ' ';
    }

    return 0;
}