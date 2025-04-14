#include <iostream>
using namespace std;

void sieve();
bool prime[1000001];

int main(){
    int T;
    cin >> T;

    sieve();

    while (T--){
        int N;
        cin >> N;

        int cnt = 0;
        for (int i = 2; i <= N / 2; i++){
            if (prime[i] && prime[N-i]) cnt++;
        }

        cout << cnt << '\n';
    }
    return 0;
}

void sieve(){
    fill(prime, prime + 1000001, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= 1000000; i++){
        if (prime[i]){
            for (int j = i * i; j <= 1000000; j+=i){
                prime[j] = false;
            }
        }
    }
}