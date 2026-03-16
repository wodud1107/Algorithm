#include <iostream>
#include <vector>
using namespace std;

int N;
int answer;

vector<vector<int>> rotate(vector<vector<int>> board, int dir) {
    vector<vector<int>> temp = board;
    for (int c = 0; c < dir; c++) {
        vector<vector<int>> rotated(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                rotated[N - 1 - j][i] = temp[i][j];
            }
        }
        temp = rotated;
    }
    return temp;
}

vector<vector<int>> move(vector<vector<int>> board, int dir) {
    vector<vector<int>> rotated = rotate(board, dir);
    vector<vector<int>> temp(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        vector<int> nums;
        for (int j = 0; j < N; j++) {
            if (rotated[i][j] != 0) nums.push_back(rotated[i][j]);
        }
        vector<int> merged;
        int idx = 0;
        while (idx < nums.size()) {
            if (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
                merged.push_back(nums[idx] * 2);
                idx += 2;
            }
            else {
                merged.push_back(nums[idx]);
                idx += 1;
            }
        }

        while (merged.size() < N) {
            merged.push_back(0);
        }

        temp[i] = merged;
    }

    return rotate(temp, 4 - dir);
}

void dfs(vector<vector<int>> board, int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] > answer) answer = board[i][j];
            }
        }
        return;
    }

    vector<int> dir = { 0, 1, 2, 3 };
    for (int i = 0; i < 4; i++) {
        vector<vector<int>> temp_board = move(board, dir[i]);
        dfs(temp_board, cnt + 1);
    }
}

int main() {
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            cin >> val;
            board[i][j] = val;
        }
    }

    dfs(board, 0);

    cout << answer;
}