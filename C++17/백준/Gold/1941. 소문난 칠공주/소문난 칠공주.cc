#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<char>> seats(5, vector<char>(5, ' '));
vector<int> members;
int answer;

bool check(const auto& members) {
    int s_cnt = 0;
    vector<vector<bool>> temp(5, vector<bool>(5, false));
    for (int i = 0; i < 7; i++) {
        int x = members[i] / 5;
        int y = members[i] % 5;

        if (seats[x][y] == 'S') s_cnt++;
        temp[x][y] = true;
    }

    if (s_cnt < 4) return false;

    int first_x = members[0] / 5;
    int first_y = members[0] % 5;

    vector<vector<bool>> visited(5, vector<bool>(5, false));
    visited[first_x][first_y] = true;
    temp[first_x][first_y] = false;
    queue<pair<int, int>> q;
    q.push({ first_x, first_y });

    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && !visited[nx][ny] && temp[nx][ny]) {
                visited[nx][ny] = true;
                temp[nx][ny] = false;
                q.push({ nx, ny });
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (temp[i][j]) return false;
        }
    }
    return true;
}

void dfs(int idx) {
    if (members.size() == 7) {
        if (check(members)) answer++;
        return;
    }

    for (int i = idx; i < 25; i++) {
        members.push_back(i);
        dfs(i + 1);
        members.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            seats[i][j] = s[j];
        }
    }

    dfs(0);
    cout << answer;

    return 0;
}