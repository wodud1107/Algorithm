#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    long long dist[100000], price[100001];
    for (int i = 0; i < N - 1; i++) cin >> dist[i];
    for (int i = 0; i < N; i++) cin >> price[i];

    long long answer = 0;
    long long min_price = price[0];
    for (int i = 0; i < N - 1; i++){
        if (min_price > price[i]){
            min_price = price[i];
        }
        answer += min_price * dist[i];
    }

    cout << answer << '\n';

    return 0;
}