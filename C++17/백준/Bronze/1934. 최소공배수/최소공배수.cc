#include <iostream>
using namespace std;

int gcd(int A, int B);
int lcm(int A, int B);

int main(){
    int T;
    cin >> T;
    
    while (T--){
        int A, B;
        cin >> A >> B;

        cout << lcm(A, B) << '\n';
    }

    return 0;
}

int gcd(int A, int B){
    return B == 0 ? A : gcd(B, A % B);
}

int lcm(int A, int B){
    return (A * B) / gcd(A, B);
}