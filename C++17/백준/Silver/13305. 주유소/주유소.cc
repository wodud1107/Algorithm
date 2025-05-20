#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    long long dist[100000], price[100001];
    long long total_d = 0;
    for (int i = 0; i < N - 1; i++){
        int x;
        cin >> x;
        dist[i] = x;

        total_d += x;
    }

    for (int i = 0; i < N; i++) cin >> price[i];

    long long answer = 0;
    long long min_price = price[0] * total_d;
    long long cumulative_price = 0;
    for (int i = 0; i < N - 1; i++){
        long long rest_d = total_d - dist[i];
        
        cumulative_price += dist[i] * price[i];
        min_price = min(min_price, price[i + 1] * rest_d + cumulative_price);
    }

    cout << min_price << '\n';

    return 0;
}