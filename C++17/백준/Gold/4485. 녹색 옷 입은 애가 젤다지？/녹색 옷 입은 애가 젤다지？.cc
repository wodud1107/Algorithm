#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int cost;
    int x;
    int y;

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<int> answer;
    while (true) {
        cin >> N;
        if (N == 0) break;

        vector<vector<int>> board(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }

        vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
        dist[0][0] = board[0][0];
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({ board[0][0], 0, 0 });

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            if (current.x == N - 1 && current.y == N - 1) {
                answer.push_back(current.cost);
                break;
            }
            
            if (current.cost > dist[current.x][current.y]) continue;

            vector<int> dx = { -1, 1, 0, 0 };
            vector<int> dy = { 0, 0, -1, 1 };
            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];

                if (0 <= nx && nx < N && 0 <= ny && ny < N && dist[nx][ny] > board[nx][ny] + current.cost) {
                    dist[nx][ny] = board[nx][ny] + current.cost;
                    pq.push({ dist[nx][ny], nx, ny });
                }
            }
        }
    }

    for (int i = 0; i < answer.size(); i++)
        cout << "Problem " << i + 1 << ": " << answer[i] << '\n';

    return 0;
}