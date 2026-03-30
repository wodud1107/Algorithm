#include <iostream>
#include <vector>
using namespace std;

int N, remv;
int parent[50];
vector<vector<int>> tree;

int dfs(int node) {
    if (tree[node].empty()) return 1;

    int total_leaves = 0;
    for (int child : tree[node]) {
        total_leaves += dfs(child);
    }

    return total_leaves;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> parent[i];
    }
    cin >> remv;

    int root = -1;
    tree.resize(N, vector<int>());
    for (int i = 0; i < N; i++) {
        if (parent[i] == -1) root = i;
        else {
            if (i != remv) tree[parent[i]].push_back(i);
        }
    }

    if (remv == root) {
        cout << 0;
        return 0;
    }

    cout << dfs(root);

    return 0;
}