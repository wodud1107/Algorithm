#include <iostream>
using namespace std;

int N, M, H;
bool ladders[31][11];
int answer = -1;

bool check() {
    for (int j = 1; j <= N; j++) {
        int curr = j;
        for (int i = 1; i <= H; i++) {
            if (ladders[i][curr]) curr++;
            else if (curr > 1 && ladders[i][curr - 1]) curr--;
        }
        if (curr != j) return false;
    }
    return true;
}

void dfs(int cnt, int target) {
    if (answer != -1) return;

    if (cnt == target) {        
        if (check()) {
            answer = cnt;
        }
        return;
    }

    for (int j = 1; j < N; j++) {
        for (int i = 1; i <= H; i++) {
            if (ladders[i][j]) continue;
            if (j > 1 && ladders[i][j - 1]) continue;
            if (j < N - 1 && ladders[i][j + 1]) continue;

            ladders[i][j] = true;
            dfs(cnt + 1, target);
            ladders[i][j] = false;
            while (i <= H && !ladders[i][j - 1] && !ladders[i][j + 1]) i++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladders[a][b] = true;
    }

    if (check()) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i < 4; i++) {
        dfs(0, i);
        if (answer != -1) break;
    }

    cout << answer << '\n';

    return 0;
}