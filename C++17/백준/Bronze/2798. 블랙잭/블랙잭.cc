#include <iostream>

using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    
    int num[N];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int sum = num[i] + num[j] + num[k];
                if (sum == M) {
                    answer = sum;
                    break;
                }
                else if (sum > M) {
                    continue;
                } else {
                    answer = max(answer, sum);
                }
            }
        }
    }

    cout << answer << endl;
    
    return 0;
}