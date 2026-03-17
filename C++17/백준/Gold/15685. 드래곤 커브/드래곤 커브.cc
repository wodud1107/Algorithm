#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<vector<bool>> board(101, vector<bool>(101, false));

    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> dx = { 1, 0, -1, 0 };
        vector<int> dy = { 0, -1, 0, 1 };

        vector<int> dirs({ d });
        for (int j = 0; j < g; j++) {
            vector<int> reversed = dirs;
            reverse(reversed.begin(), reversed.end());
            for (int k = 0; k < reversed.size(); k++)
                reversed[k] = (reversed[k] + 1) % 4;
            dirs.insert(dirs.end(), reversed.begin(), reversed.end());
        }

        board[x][y] = true;
        int curr_x = x;
        int curr_y = y;
        for (int j = 0; j < dirs.size(); j++) {
            curr_x += dx[dirs[j]];
            curr_y += dy[dirs[j]];
            
            if (0 <= curr_x && curr_y < 101 && 0 <= curr_y && curr_y < 101)
                board[curr_x][curr_y] = true;
        }
    }

    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1]) answer++;
        }
    }

    cout << answer;

    return 0;
}