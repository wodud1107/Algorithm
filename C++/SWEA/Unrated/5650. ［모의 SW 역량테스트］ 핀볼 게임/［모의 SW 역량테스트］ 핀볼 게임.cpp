#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
using pii = pair<int, int>;

int N;
int board[100][100];
pii dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		memset(board, 0, sizeof(board));

		vector<pii> starts;
		vector<vector<pii>> holes(11, vector<pii>());
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];

				if (board[i][j] == 0) starts.push_back({i, j});
				if (6 <= board[i][j] && board[i][j] <= 10) holes[board[i][j]].push_back({i, j});
			}
		}
		
		int answer = 0;
		for (auto [x, y] : starts) {
			for (int d = 0; d < 4; d++) {
				bool seen[100][100][4] = {};
				int cd = d, cx = x, cy = y, pt = 0;
				while (1) {
					if (seen[cx][cy][cd]) {
						cout << "cycle: start=(" << x << "," << y << "), dir=" << d
						<< " cur=(" << cx << "," << cy << "), cd=" << cd << '\n';
						break;
					}
					seen[cx][cy][cd] = true;
					int dx = dir[cd].first, dy = dir[cd].second;
					int px = cx, py = cy;
					cx += dx;
					cy += dy;
					
					if (!(0 <= cx && cx < N && 0 <= cy && cy < N)) {
						switch (cd) {
							case 0: cd = 1; break;
							case 1: cd = 0; break;
							case 2: cd = 3; break;
							case 3: cd = 2; break;
						}
						cx = px;
						cy = py;
						pt++;
					}

					if ((cx == x && cy == y) || board[cx][cy] == -1) {
						answer = max(answer, pt);
						break;
					}
					
					switch (board[cx][cy]) {
						case -1: case 0:
							break;

						case 1: {
							pt++;
							switch (cd) {
								case 0: cd = 1; break;
								case 1: cd = 3; break;
								case 2: cd = 0; break;
								case 3: cd = 2; break;
							}
							break;
						}

						case 2: {
							pt++;
							switch (cd) {
								case 0: cd = 3; break;
								case 1: cd = 0; break;
								case 2: cd = 1; break;
								case 3: cd = 2; break;
							}
							break;
						}

						case 3: {
							pt++;
							switch (cd) {
								case 0: cd = 2; break;
								case 1: cd = 0; break;
								case 2: cd = 3; break;
								case 3: cd = 1; break;
							}
							break;
						}

						case 4: {
							pt++;
							switch (cd) {
								case 0: cd = 1; break;
								case 1: cd = 2; break;
								case 2: cd = 3; break;
								case 3: cd = 0; break;
							}
							break;
						}
						
						case 5: {
							pt++;
							switch (cd) {
								case 0: cd = 1; break;
								case 1: cd = 0; break;
								case 2: cd = 3; break;
								case 3: cd = 2; break;
							}
							break;
						}
						
						default: {
							int hole_id = board[cx][cy];
							int warp_x = -1, warp_y = -1;
							for (auto [hx, hy] : holes[hole_id]) {
								if (hx == cx && hy == cy) continue;
								warp_x = hx;
								warp_y = hy;
							}
							
							cx = warp_x;
							cy = warp_y;
							break;
						}
					}
				}
			}
		}

		cout << '#' << test_case << ' ' << answer << '\n';
	}
    return 0;
}