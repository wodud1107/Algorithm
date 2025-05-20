#include <iostream>
using namespace std;

int N, white = 0, blue = 0, board[128][128];

bool sameColor(int x, int y, int size){
    int color = board[x][y];
    for (int i = x; i < x + size; i++){
        for (int j = y; j < y + size; j++){
            if (board[i][j] != color) return false;
        }
    }
    return true;
}

void divide(int x, int y, int size){
    if (sameColor(x, y, size)){
        if (board[x][y] == 0) white++;
        else blue++;
        return;
    }

    int newSize = size / 2;
    divide(x, y, newSize);
    divide(x, y + newSize, newSize);
    divide(x + newSize, y, newSize);
    divide(x + newSize, y + newSize, newSize);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    divide(0, 0, N);

    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}