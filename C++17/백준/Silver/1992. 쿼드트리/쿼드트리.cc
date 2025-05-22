#include <iostream>
using namespace std;

int N, board[64][64];
string s = "";

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
        s += to_string(board[x][y]);
        return;
    }
    
    s += '(';
    int newSize = size / 2;
    divide(x, y, newSize);
    divide(x, y + newSize, newSize);
    divide(x + newSize, y, newSize);
    divide(x + newSize, y + newSize, newSize);
    s += ')';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++){
        string line;
        cin >> line;
        for (int j = 0; j < N; j++){
            board[i][j] = line[j] - '0';
        }
    }

    divide(0, 0, N);

    cout << s << '\n';

    return 0;
}