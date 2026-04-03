#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int N, M;
int board[10][10];

int id = 2;
vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Edge {
    int u, v, w;
};

vector<Edge> edges;
int parent[20];

void find_island(int sx, int sy) {
    queue<pii> q;
    board[sx][sy] = id;
    q.emplace(sx, sy);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (const auto& [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;

            if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] == 1) {
                board[nx][ny] = id;
                q.emplace(nx, ny);
            } 
        }
    }
    id++;
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 20; i++) parent[i] = i;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) {
                find_island(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] < 2) continue;

            int from = board[i][j];
            for (auto [dx, dy] : dirs) {
                int nx = i + dx;
                int ny = j + dy;
                int len = 0;

                while (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    if (board[nx][ny] == from) break;

                    if (board[nx][ny] == 0) {
                        len++;
                        nx += dx;
                        ny += dy;
                        continue;
                    }

                    if (len >= 2) {
                        int to = board[nx][ny];
                        edges.push_back({from, to, len});
                    }
                    break;
                }
            }
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return a.w < b.w;
    });

    int total = 0;
    int used = 0;
    for (auto& e : edges) {
        if (unite(e.u, e.v)) {
            total += e.w;
            used++;
        }

        if (used == id - 3) break;
    }

    if (used != id - 3) cout << -1;
    else cout << total;

    return 0;
}