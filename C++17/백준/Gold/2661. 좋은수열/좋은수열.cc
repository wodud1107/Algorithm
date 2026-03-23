#include <iostream>
#include <vector>
using namespace std;

int N;
void solve(int N, vector<int>& seq) {
    int length = seq.size();

    for (int i = 1; i < length / 2 + 1; i++) {
        vector<int> left(seq.end() + (-2 * i), seq.end() + (-2 * i) + i);
        vector<int> right(seq.end() - i, seq.end());

        if (left == right) return;
    }


    if (length == N) {
        for (int i = 0; i < N; i++) {
            cout << seq[i];
        }
        exit(0);
    }

    for (int i = 1; i < 4; i++) {
        seq.push_back(i);
        solve(N, seq);
        seq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> init_seq = {1};
    solve(N, init_seq);    

    return 0;
}