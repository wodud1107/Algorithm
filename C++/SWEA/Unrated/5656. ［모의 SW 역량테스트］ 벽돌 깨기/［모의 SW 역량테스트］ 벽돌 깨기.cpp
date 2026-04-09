#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using pii = pair<int, int>;

int N, W, H;
vector<vector<int>> board;
int answer;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<int>> broken(int x, int y, vector<vector<int>> curr_board) {
    int visited[15][12] = { 0 };
    queue<pii> q;
    q.push({x, y});
    visited[x][y] = 1;
    
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        
        int range = curr_board[cx][cy];
        curr_board[cx][cy] = 0;
        if (range <= 1) continue;
        for (int i = 0; i < 4; i++) {
            for (int s = 1; s < range; s++) {
                int nx = cx + dx[i] * s;
                int ny = cy + dy[i] * s;

                if (0 <= nx && nx < H && 0 <= ny && ny < W && !visited[nx][ny]) {
                    if (curr_board[nx][ny] != 0) {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return curr_board;
}

void dfs(int cnt, vector<vector<int>> curr_board) {
    if (answer == 0) return;
    int bricks = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (curr_board[i][j] != 0) bricks++;
        }
    }
    if (bricks == 0) {
        answer = 0;
        return;
    }

    if (cnt == N) {
        answer = min(answer, bricks);
        return;
    }

    for (int j = 0; j < W; j++) {
        int target = -1;
        for (int i = 0; i < H; i++) {
            if (curr_board[i][j] != 0) {
                target = i;
                break;
            }
        }
            
        if (target == -1) {
            dfs(cnt + 1, curr_board);
            continue;
        }

        vector<vector<int>> broken_board = broken(target, j, curr_board);
        for (int y = 0; y < W; y++) {
            vector<int> cols;
            for (int x = 0; x < H; x++) {
                if (broken_board[x][y] != 0) {
                    cols.push_back(broken_board[x][y]);
                }
            }
            
            for (int x = H - 1; x >= 0; x--) {
                if (cols.empty()) broken_board[x][y] = 0;
                else {
                    broken_board[x][y] = cols.back();
                    cols.pop_back();
                }
            }
        }
        dfs(cnt + 1, broken_board);
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> W >> H;
        answer = W * H;
        board.assign(H, vector<int>(W, 0));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> board[i][j];
            }
        }

        dfs(0, board);

        cout << '#' << test_case << ' ' << answer << '\n';
	}
	return 0;
}