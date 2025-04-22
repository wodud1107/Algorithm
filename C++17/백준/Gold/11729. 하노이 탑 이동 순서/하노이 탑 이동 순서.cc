#include <cstdio>
#include <string>

std::string result;

void hanoi(int N, int a, int b, int c){
    if (N >= 1) {
        hanoi(N - 1, a, c, b);
        result += std::to_string(a) + ' ' + std::to_string(c) + '\n';
        hanoi(N - 1, b, a, c);
        return;
    }
}

int main(){
    int N;
    scanf("%d", &N);
    
    printf("%d\n", (1 << N) - 1);
    hanoi(N, 1, 2, 3);
    printf("%s", result.c_str());

    return 0;
}