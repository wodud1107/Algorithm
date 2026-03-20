#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char seats[25];
vector<int> members;
int answer;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool check() {
    bool temp[25] = { false };
    for (int i = 0; i < 7; i++)
        temp[members[i]] = true;

    bool visited[25] = { false };
    visited[members[0]] = true;
    temp[members[0]] = false;
    queue<int> q;
    q.push({ members[0] });


    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int x = curr / 5;
        int y = curr % 5;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && !visited[nx * 5 + ny] && temp[nx * 5 + ny]) {
                visited[nx * 5 + ny] = true;
                temp[nx * 5 + ny] = false;
                q.push(nx * 5 + ny);
            }
        }
    }

    for (int i = 0; i < 25; i++) {
        if (temp[i]) return false;
    }
    return true;
}

void dfs(int idx, int y_cnt) {
    if (y_cnt >= 4) return;

    if (members.size() == 7) {
        if (check()) answer++;
        return;
    }

    for (int i = idx; i < 25; i++) {
        members.push_back(i);
        int next_y_cnt = y_cnt + (seats[i] == 'Y' ? 1 : 0);
        dfs(i + 1, next_y_cnt);
        members.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 25; i++) {
        cin >> seats[i];
    }

    dfs(0, 0);
    cout << answer;

    return 0;
}