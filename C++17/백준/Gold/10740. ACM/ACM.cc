#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> prefix(3, vector<int>(N + 1, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= N; j++) {
            int diff;
            cin >> diff;
            prefix[i][j] = prefix[i][j - 1] + diff;
        }
    }

    int min_difficulty = 5 * N;
    vector<int> p = {0, 1, 2};

    do {
        int p1 = p[0];
        int p2 = p[1];
        int p3 = p[2];

        int min_prev_diff = 5 * N;
        for (int j = 2; j < N; j++) {
            int i = j - 1;
            int cur_diff = prefix[p1][i] - prefix[p2][i];
            min_prev_diff = min(min_prev_diff, cur_diff);

            int result = min_prev_diff + prefix[p2][j] - prefix[p3][j] + prefix[p3][N];
            min_difficulty = min(min_difficulty, result);
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << min_difficulty;

    return 0;
}