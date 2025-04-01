#include <iostream>

using namespace std;
int main() {
    int N, M;
    cin >> N >> M;

    bool board[N][M];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            char input;
            cin >> input;
            if (input == 'W') board[i][j] = true;
            else board[i][j] = false;
        }
    }

    int cnt_min = 50 * 50;
    for (int x = 0; x + 7 < N; x++){
        for (int y = 0; y + 7 < M; y++){
            int W_cnt = 0, B_cnt = 0;
            for (int i = x; i < x + 8; i++){
                for (int j = y; j < y + 8; j++){
                    if ((i - x + j - y) % 2 == 0){
                        if (!board[i][j]) W_cnt++;
                        else B_cnt++;
                    } else {
                        if (!board[i][j]) B_cnt++;
                        else W_cnt++;
                    }
                }
            }

            cnt_min = min(cnt_min, min(W_cnt, B_cnt));
        }
    }

    cout << cnt_min << endl;

    return 0;
}