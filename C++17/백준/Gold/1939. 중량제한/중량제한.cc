#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int start = 0, end = 0;
    vector<vector<pair<int, int>>> bridges(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        end = max(end, C);
        bridges[A].push_back({ B, C });
        bridges[B].push_back({ A, C });
    }
    int fact1, fact2;
    cin >> fact1 >> fact2;

    while (start <= end) {
        int mid = (start + end) >> 1;
        
        bool is_reached = false;
        vector<bool> visited(N + 1, false);
        visited[fact1] = true;
        queue<int> q;
        q.push(fact1);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == fact2) {
                start = mid + 1;
                is_reached = true;
                break;
            }

            for (const auto& edge: bridges[curr]) {
                int next = edge.first;
                int weight = edge.second;

                if (!visited[next] && weight >= mid) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        if (!is_reached) end = mid - 1;
    }

    cout << end;

    return 0;
}