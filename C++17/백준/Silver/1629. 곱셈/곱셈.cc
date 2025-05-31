#include <iostream>
using namespace std;

typedef long long ll;

ll mod_pow(ll A, ll B, ll C){
    if (B == 0) return 1;

    ll half = mod_pow(A, B / 2, C);
    ll result = (half * half) % C;

    if (B % 2 == 1) result = (result * A) % C;

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll A, B, C;
    cin >> A >> B >> C;

    cout << mod_pow(A, B, C) << '\n';

    return 0;
}