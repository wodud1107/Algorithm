#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct Cell {
    int x, y;
    int power;
    int born;
};

int N, M, K;
int board[650][650];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M >> K;
        memset(board, 0, sizeof(board));
        vector<Cell> cells;
        for (int i = 300; i < 300 + N; i++) {
            for (int j = 300; j < 300 + M; j++) {
                cin >> board[i][j];
                if (board[i][j] != 0) cells.push_back({i, j, board[i][j], 0});
            }
        }

        int t = 0;
        while (t++ < K) {
            map<pair<int, int>, int> candidates;

            for (auto &cell : cells) {
                if (t == cell.born + cell.power + 1) {
                    for (int i = 0; i < 4; i++) {
                        int nx = cell.x + dx[i];
                        int ny = cell.y + dy[i];

                        if (board[nx][ny]) continue;
                        pair<int, int> key = {nx, ny};
                        candidates[key] = max(candidates[key], cell.power);
                    }
                }
            }

            for (auto &[pos, power] : candidates) {
                auto [x, y] = pos;
                if (board[x][y]) continue;
                board[x][y] = 1;
                cells.push_back({x, y, power, t});
            }
        }

        int answer = 0;
        for (auto &cell: cells) {
            if (cell.born + 2 * cell.power > K) {
                answer++;
            }
        }

        cout << '#' << test_case << ' ' << answer << '\n';
	}
    return 0;
}