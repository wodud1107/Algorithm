#include <iostream>
using namespace std;

long long int gcd(long long int A, long long int B);
long long int lcm(long long int A, long long int B);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long int A, B;
    cin >> A >> B;

    cout << lcm(A, B) << '\n';

    return 0;
}

long long int gcd(long long int A,long long int B){
    return B == 0 ? A : gcd(B, A % B);
}

long long int lcm(long long int A, long long int B){
    return (A * B) / gcd(A, B);
}