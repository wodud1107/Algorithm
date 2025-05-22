#include <iostream>
using namespace std;

int N, board[2187][2187];
int p1 = 0, p2 = 0, p3 = 0;

bool sameColor(int x, int y, int size){
    for (int i = x; i < x + size; i++){
        for (int j = y; j < y + size; j++){
            if (board[i][j] != board[x][y]) return false;
        }
    }
    return true;
}

void divide(int x, int y, int size){
    if(sameColor(x, y, size)){
        if (board[x][y] == 0) p1++;
        else if (board[x][y] == 1) p2++;
        else p3++;
        return;
    }

    int reSize = size / 3;
    divide(x, y, reSize);
    divide(x + reSize, y, reSize);
    divide(x, y + reSize, reSize);
    divide(x + reSize, y + reSize, reSize);
    divide(x + 2 * reSize, y, reSize);
    divide(x, y + 2 * reSize, reSize);
    divide(x + 2 * reSize, y + 2 * reSize, reSize);
    divide(x + reSize, y + 2 * reSize, reSize);
    divide(x + 2 * reSize, y + reSize, reSize);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    divide(0, 0, N);

    cout << p3 << '\n' << p1 << '\n' << p2 << '\n';

    return 0;
}