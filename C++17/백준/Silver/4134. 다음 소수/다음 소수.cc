#include <iostream>
using namespace std;

bool isPrime(long n);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--){
        long x;
        cin >> x;

        if (x <= 2) {
            cout << 2 << '\n';
            continue;
        }
        while (!isPrime(x)){
            x++;
        }

        cout << x << '\n';
    }

    return 0;
}

bool isPrime(long n){
    long div = 2;
    while (div * div <= n){
        if (n % div == 0) return false;
        else div ++;
    }
    return true;
}