#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
using Matrix = vector<vector<ll>>;
#define MOD 1000000007

Matrix mul(const Matrix &A, const Matrix &B){
    Matrix C(2, vector<ll>(2));
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return C;
}

Matrix power(Matrix A, ll exp){
    Matrix result = {{1, 0}, {0, 1}};

    while(exp > 0){
        if (exp % 2 == 1) result = mul(result, A);
        A = mul(A, A);
        exp /= 2;
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    if (n == 0){
        cout << 0 << '\n';
        return 0;
    }

    Matrix F = {{1, 1}, {1, 0}};
    Matrix res = power(F, n - 1);
    cout << res[0][0] << '\n';

    return 0;
}