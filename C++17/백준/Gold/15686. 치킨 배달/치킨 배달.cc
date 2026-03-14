#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chicken;
vector<bool> selected;
int answer = 50 * 50;

void calculate() {
    int dist = 0;

    for (int i = 0; i < houses.size(); i++) {
        int hx = houses[i].first;
        int hy = houses[i].second;
        int chick_dist = 50 * 50;

        for (int j = 0; j < chicken.size(); j++) {
            if (selected[j]) {
                int cx = chicken[j].first;
                int cy = chicken[j].second;

                chick_dist = min(chick_dist, abs(hx - cx) + abs(hy - cy));
            }
        }
        dist += chick_dist;
    }

    answer = min(answer, dist);
}

void dfs(int idx, int cnt) {
    if (cnt == M) {
        calculate();
        return;
    }

    for (int i = idx; i < chicken.size(); i++) {
        if (selected[i]) continue;

        selected[i] = true;
        dfs(i + 1, cnt + 1);
        selected[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int value;
            cin >> value;

            if (value == 1) {
                houses.push_back({ i, j });
            }
            if (value == 2) {
                chicken.push_back({ i, j });
            }
        }
    }

    selected.resize(chicken.size(), false);
    dfs(0, 0);

    cout << answer;
    
    return 0;
}