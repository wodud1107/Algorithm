#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int num[N][N + 1];
    memset(num, 0, sizeof(num));
    for (int i = 0; i < N; i++){
        num[i][0] = 0;
        for (int j = 1; j <= N; j++){
            int x;
            cin >> x;
            num[i][j] = num[i][j - 1] + x;
        }
    }

    while (M--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = 0;
        for (int i = x1 - 1; i < x2; i++){
            sum += num[i][y2] - num[i][y1 - 1];
        }

        cout << sum << '\n';
    }

    return 0;
}