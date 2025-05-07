#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    long long count[M];
    fill(count, count + M, 0);
    long long sum = 0, answer = 0;
    for (int i = 1; i <= N; i++){
        long long x;
        cin >> x;

        sum += x % M;
        if (sum % M == 0) answer++;

        count[sum % M]++;
    }

    for (long long c : count){
        answer += c * (c - 1) / 2;
    }

    cout << answer << '\n';

    return 0;
}