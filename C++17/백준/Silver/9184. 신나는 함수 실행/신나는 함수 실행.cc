#include <cstdio>
using namespace std;

int dp[21][21][21];

bool inRange(int a, int b, int c){
    return 0 <= a && a <= 20 && 0 <= b && b <= 20 && 0 <= c && c <= 20;
}

int w(int a, int b, int c){
    if (inRange(a, b, c) && dp[a][b][c] != 0) return dp[a][b][c];

    if (a <= 0 || b <= 0 || c <= 0){
        return dp[0][0][0] = 1;
    }

    if (a > 20 || b > 20 || c > 20){
        return dp[20][20][20] = w(20, 20, 20);
    }

    if (a < b && b < c){
        return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }

    return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(){
    int a, b, c;
    
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;

        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}