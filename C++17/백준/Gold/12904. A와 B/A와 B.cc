#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> T;
    while (T.size() > S.size()) {
        char last = T.back();
        T.pop_back();
        if (last == 'B') {
            reverse(T.begin(), T.end());
        }
    }
    cout << (S == T);

    return 0;
}