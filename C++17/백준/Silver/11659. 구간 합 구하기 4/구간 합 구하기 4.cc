#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    int num[N + 1];
    fill(num, num + N + 1, 0);
    for (int i = 1; i <= N; i++){
        int x;
        cin >> x;

        num[i] = num[i - 1] + x;
    }

    while (M--){
        int i, j;
        cin >> i >> j;

        cout << num[j] - num[i - 1] << '\n';
    }

    return 0;
}