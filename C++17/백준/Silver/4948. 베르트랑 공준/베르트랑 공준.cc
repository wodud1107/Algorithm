#include <iostream>
using namespace std;

bool isPrime(int n);

int main(){
    while(1){
        int x;
        cin >> x;

        if (x == 0) break;

        int cnt = 0;
        for (int i = x + 1; i <= 2 * x; i++){
            if(isPrime(i)) cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}

bool isPrime(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i++){
        if (n % i == 0) return false;
    }

    return true;
}