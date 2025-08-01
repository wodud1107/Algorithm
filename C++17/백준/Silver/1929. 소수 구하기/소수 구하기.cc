#include <iostream>
using namespace std;

bool isPrime(int n);

int main(){
    int M, N;
    cin >> M >> N;

    for (int i = M; i <= N; i++){
        if (isPrime(i)){
            cout << i << '\n';
        }
    }

    return 0;
}

bool isPrime(int n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i++){
        if (n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }

    return true;
}