#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    int lis[N], lds[N];
    fill(lis, lis + N, 1);
    fill(lds, lds + N, 1);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < i; j++){
            if (A[j] < A[i]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    for (int i = N - 1; i >= 0; i--){
        for (int j = N - 1; j > i; j--){
            if (A[j] < A[i]){
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++){
        res = max(res, lis[i] + lds[i] - 1);
    }
    
    cout << res << '\n';

    return 0;
}