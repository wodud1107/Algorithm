#include <iostream>
using namespace std;

int main(){
    int N; cin >> N;

    int factorial[13];
    fill(factorial, factorial + 13, 1);
    for (int i = 1; i <= N; i++){
        factorial[i] = factorial[i-1] * i;
    }

    cout << factorial[N] << '\n';
    
    return 0;
}