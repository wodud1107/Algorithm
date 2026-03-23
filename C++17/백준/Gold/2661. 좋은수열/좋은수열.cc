#include <iostream>
#include <string>
using namespace std;

int N;
void solve(int N, string& seq) {
    int len = seq.length();

    for (int i = 1; i < len / 2 + 1; i++) {
        string left = seq.substr(len - 2 * i, i);
        string right = seq.substr(len - i, i);

        if (left == right) return;
    }


    if (len == N) {
        cout << seq;
        exit(0);
    }

    for (int i = 1; i < 4; i++) {
        seq.push_back(i + '0');
        solve(N, seq);
        seq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    string init_seq = "1";
    solve(N, init_seq);    

    return 0;
}