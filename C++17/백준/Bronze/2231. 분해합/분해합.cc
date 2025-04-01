#include <iostream>

using namespace std;
int main() {
    int N;
    cin >> N;

    for (int i = 1 ; i < N; i++) {
        int sum = i;
        int tmp = i;
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }

        if (sum == N){
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}