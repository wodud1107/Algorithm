#include <cstdio>
#include <cstring>

char board[2188][2188];

void star(int N, int x, int y){
    if (N == 1){
        board[x][y] = '*';
        return;
    }

    int part = N / 3;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == 1 && j == 1) continue;
            star(part, x + i * part, y + j * part);
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);

    std::memset(board, ' ', sizeof(board));

    star(N, 0, 0);

    for (int i = 0; i < N; i++){
        board[i][N] = '\0';
        printf("%s\n", board[i]);
    }

    return 0;
}