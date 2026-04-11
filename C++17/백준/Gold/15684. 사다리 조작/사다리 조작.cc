#include <iostream>
using namespace std;

int N, M, H;
int ladders[31][11];
int answer = -1;

void dfs(int x, int y, int cnt, int target) {
    if (cnt == target) {        
        bool good = true;
        for (int j = 1; j <= N; j++) {
            int curr = j;
            for (int i = 1; i <= H; i++) {
                curr = ladders[i][curr];
            }
            if (curr != j) good = false;
        }

        if (good) {
            answer = cnt;
        }
        return;
    }

    for (int i = x; i <= H; i++) {
        int start = (i == x) ? y : 1;

        for (int j = start; j < N; j++) {
            if (ladders[i][j] == j && ladders[i][j + 1] == j + 1) {
                ladders[i][j] = j + 1;
                ladders[i][j + 1] = j;

                dfs(i, j + 2, cnt + 1, target);

                ladders[i][j] = j;
                ladders[i][j + 1] = j + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> H;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= N; j++) {
            ladders[i][j] = j;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        swap(ladders[a][b], ladders[a][b + 1]);
    }

    for (int i = 0; i < 4; i++) {
        dfs(1, 1, 0, i);
        if (answer != -1) break;
    }

    cout << answer << '\n';

    return 0;
}