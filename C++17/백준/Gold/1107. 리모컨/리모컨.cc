#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    bool broken[10] = { false };
    for (int i = 0; i < M; i++) {
        int err;
        cin >> err;
        broken[err] = true;
    }

    int answer = abs(N - 100);
    for (int num = 0; num < 1000001; num++) {
        string num_str = to_string(num);

        bool is_broken = false;
        for (char c : num_str) {
            int a = c - '0';
            if (broken[a]) {
                is_broken = true;
                break;
            }
        }

        if (!is_broken) {
            int cnt = num_str.size() + abs(N - num);
            answer = answer > cnt ? cnt : answer;
        }
    }

    cout << answer;

    return 0;
}