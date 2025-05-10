#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int board[2001][2001];

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            char c;
            cin >> c;

            if (((i + j) % 2 == 0 && c != 'B') || ((i + j) % 2 != 0 && c == 'B')){
                board[i][j] = 1;
            }
            board[i][j] += board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1];
        }
    }

    int ans = INT_MAX;
    for (int i = K; i <= N; i++){
        for (int j = K; j <= M; j++){
            int tmp = board[i][j] - board[i - K][j] - board[i][j - K] + board[i - K][j - K];
            int rePaint = K * K - tmp;

            ans = min({ans, tmp, rePaint});
        }
    }

    cout << ans << '\n';

    return 0;
}