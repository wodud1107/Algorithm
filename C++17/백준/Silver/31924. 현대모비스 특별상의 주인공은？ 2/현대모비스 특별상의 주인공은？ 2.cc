#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> board(N);

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    string target = "MOBIS";
    int dx[8] = {-1, -1, 1, 1, -1, 1, 0, 0};
    int dy[8] = {-1, 1, -1, 1, 0, 0, -1, 1};

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int dir = 0; dir < 8; dir++) {
                bool match = true;

                for (int k = 0; k < 5; k++) {
                    int ni = i + dx[dir] * k;
                    int nj = j + dy[dir] * k;

                    if (ni < 0 || ni >= N || nj < 0 || nj >= N || board[ni][nj] != target[k]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}