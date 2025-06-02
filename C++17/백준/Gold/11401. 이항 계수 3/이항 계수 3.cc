#include <iostream>
using namespace std;

typedef long long ll;
#define MOD 1000000007

ll factorial[4000001] = {1};

ll mod_pow(ll A, ll B){
    if (B == 0) return 1;

    ll half = mod_pow(A, B / 2);
    ll result = (half * half) % MOD;

    if (B % 2 == 1) result = (result * A) % MOD;

    return result;
}

void facto(int N){
    for (int i = 1; i <= N; i++){
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    facto(N);
    ll denom = (factorial[K] * factorial[N - K]) % MOD;
    ll answer = (factorial[N] * mod_pow(denom, MOD - 2)) % MOD;
    cout << answer << '\n';

    return 0;
}