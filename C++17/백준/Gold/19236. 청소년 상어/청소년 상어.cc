#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

pii board[4][4];
pii fish[17] = {{-1, -1}};
pii dirs[8] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
pii s_pos = {0, 0};

int s_dir = 0;
int answer = 0;

void dfs(int sum, pii curr_pos, int curr_dir, pii curr_board[][4], pii curr_fish[]) {    
    for (int i = 1; i <= 16; i++) {
        auto [fx, fy] = curr_fish[i];
        if (fx == -1) continue;
        int f_dir = curr_board[fx][fy].second;
        
        while (1) {
            auto [dx, dy] = dirs[f_dir];
            int nx = fx + dx, ny = fy + dy;

            if (0 > nx || nx >= 4 || 0 > ny || ny >= 4 || curr_board[nx][ny].first == 20) {
                f_dir = (f_dir + 1) % 8;
                if (f_dir == curr_board[fx][fy].second) break;
                else continue;
            }

            curr_fish[i] = {nx, ny};
            curr_fish[curr_board[nx][ny].first] = {fx, fy};
            curr_board[fx][fy] = curr_board[nx][ny];
            curr_board[nx][ny] = {i, f_dir};
            break;
        }
    }

    auto [sx, sy] = curr_pos;
    auto [dx, dy] = dirs[curr_dir];
    vector<pii> targets;
    while (1) {
        sx += dx;
        sy += dy;
        
        if (!(0 <= sx && sx < 4 && 0 <= sy && sy < 4)) break;
        if (curr_board[sx][sy].first != 0) {
            targets.push_back({sx, sy});
        }
    }

    if (targets.empty()) {
        answer = answer < sum ? sum : answer;
        return;
    }

    for (auto [tx, ty] : targets) {
        pii next_board[4][4];
        pii next_fish[17];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                next_board[i][j] = curr_board[i][j];
                next_fish[i * 4 + j + 1] = curr_fish[i * 4 + j + 1];
            }
        }

        auto [fish_num, next_dir] = next_board[tx][ty];
        next_board[curr_pos.first][curr_pos.second] = {0, -1};
        next_board[tx][ty] = {20, next_dir};
        next_fish[fish_num] = {-1, -1};

        dfs(sum + fish_num, {tx, ty}, next_dir, next_board, next_fish);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            board[i][j] = {a, b - 1};
            if (i == 0 && j == 0) fish[a] = {-1, -1};
            else fish[a] = {i, j};
        }
    }

    answer = board[0][0].first;
    s_dir = board[0][0].second;
    board[0][0] = {20, s_dir};
    
    dfs(answer, s_pos, s_dir, board, fish);

    cout << answer << '\n';
    
    return 0;
}
