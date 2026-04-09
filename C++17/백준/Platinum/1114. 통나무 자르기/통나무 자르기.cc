#include <iostream>
#include <algorithm>
using namespace std;

int L, K, C;
int cut[10002];
int pos[10002];

int check(int size) {
    int last = L;
    int cnt = C;
    for (int i = K; i >= 0; i--) {
        if (pos[i + 1] - pos[i] > size) return -1;
        if (last - pos[i] > size) {
            cnt--;
            last = pos[i + 1];
        }
    }

    if (cnt < 0) return -1;
    if (pos[1] > size) return -1;
    if (cnt > 0) return pos[1]; 
    return last;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> K >> C;
    for (int i = 1; i <= K; i++) cin >> cut[i];
    sort(cut + 1, cut + K + 1);
    pos[0] = 0;
    for (int i = 1; i <= K; i++) pos[i] = cut[i];
    pos[K + 1] = L;

    int s = 1, e = L;
    int maximum = L;
    while (s <= e) {
        int m = (s + e) / 2;
        if (check(m) != -1) {
            maximum = m;
            e = m - 1;
        } else {
            s = m + 1;
        }
    }

    cout << maximum << ' ' << check(maximum);

    return 0;
}