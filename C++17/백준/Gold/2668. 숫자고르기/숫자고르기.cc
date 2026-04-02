#include <iostream>
#include <vector>
using namespace std;

int N;
int nums[101];
vector<int> selected;

void dfs(int num, int start, vector<bool>& visited) {
    visited[num] = true;
    int next = nums[num];

    if (!visited[next]) {
        dfs(next, start, visited);
    } else if (next == start) {
        selected.push_back(start);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
    }

    for (int i = 1; i <= N; i++) {
        vector<bool> visited(N + 1, false);
        dfs(i, i, visited);
    }

    cout << selected.size() << '\n';
    for (int i = 0; i < selected.size(); i++) {
        cout << selected[i] << '\n';
    }

    return 0;
}