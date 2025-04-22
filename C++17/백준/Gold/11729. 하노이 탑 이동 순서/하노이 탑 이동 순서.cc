#include <cstdio>

void hanoi(int N, int a, int b, int c){
    if (N >= 1) {
        hanoi(N - 1, a, c, b);
        printf("%d %d\n", a, c);
        hanoi(N - 1, b, a, c);
        return;
    }
}

int main(){
    int N;
    scanf("%d", &N);
    
    printf("%d\n", (1 << N) - 1);
    hanoi(N, 1, 2, 3);

    return 0;
}