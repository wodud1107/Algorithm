#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int P[1001];
    for (int i = 0; i < N; i++) cin >> P[i];

    sort(P, P + N);
    int sum[1002] = {0};
    for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + P[i - 1];

    int answer = 0;
    for (int i = 0; i <= N; i++) answer += sum[i];

    cout << answer << '\n';

    return 0;
}