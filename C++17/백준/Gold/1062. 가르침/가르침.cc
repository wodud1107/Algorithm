#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, K;
vector<string> words;
vector<int> word_masks;
vector<char> untaught;
int learned = 0;
int answer = 0;

void teach(int cnt, int idx) {
    if (cnt == K - 5) {
        int read_cnt = 0;
        for (int mask : word_masks) {
            if ((mask & ~learned) == 0) read_cnt++;
        }
        answer = answer > read_cnt ? answer : read_cnt;
        return;
    }

    for (int i = idx; i < untaught.size(); i++) {
        learned |= 1 << (untaught[i] - 'a');
        teach(cnt + 1, i + 1);
        learned &= ~(1 << (untaught[i] - 'a'));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    words.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }
    if (K < 5) { cout << 0; return 0; }
    if (K == 26) { cout << N; return 0; }

    char antic[5] = {'a', 'n', 't', 'i', 'c'};
    for (int i = 0; i < 5; i++) {
        learned |= 1 << (antic[i] - 'a');
    }
    for (int i = 0; i < 26; i++) {
        if (learned & (1 << i)) continue;
        untaught.push_back('a' + i);
    }

    for (int i = 0; i < N; i++) {
        int mask = 0;
        for (char c : words[i]) {
            mask |= 1 << (c - 'a');
        }
        word_masks.push_back(mask);
    }

    teach(0, 0);
    cout << answer;

    return 0;
}