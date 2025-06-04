#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
using Matrix = vector<vector<int>>;

Matrix multi(const Matrix &A, const Matrix &B){
    int N = A.size();
    Matrix res(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                res[i][j] += A[i][k] * B[k][j] % 1000;
                res[i][j] %= 1000;
            }
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    ll B;
    cin >> N >> B;

    Matrix A(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    Matrix ans(N, vector<int>(N));
    for (int i = 0; i < N; i++) ans[i][i] = 1;

    while(B > 0){
        if (B % 2 == 1) ans = multi(ans, A);
        A = multi(A, A);
        B /= 2;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << ans[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }

    return 0;
}