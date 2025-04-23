#include <iostream>
#include <cmath>
using namespace std;

int N, cnt = 0;
int board[16];

int alive(int depth);
void NQueen(int depth);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    NQueen(0);
    cout << cnt << '\n';

    return 0;
}

void NQueen(int depth){
    if (depth == N){
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++){
        board[depth] = i;

        if(alive(depth)){
            NQueen(depth + 1);
        }
    }
}

int alive(int depth){
    for (int i = 0; i < depth; i++){
        if (board[i] == board[depth] || abs(depth - i) == abs(board[depth] - board[i])){
            return 0;
        }
    }
    return 1;
}