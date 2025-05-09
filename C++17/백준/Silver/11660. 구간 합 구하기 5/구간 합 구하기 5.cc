#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int num[N + 1][N + 1];
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            int x;
            cin >> x;
            num[i][j] = num[i - 1][j] + num[i][j - 1] - num[i -1][j - 1] + x;
        }
    }

    while (M--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << num[x2][y2] - num[x1 - 1][y2] - num[x2][y1 - 1] + num[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}