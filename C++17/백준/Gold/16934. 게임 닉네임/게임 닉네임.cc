#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int N;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    unordered_set<string> prefixes;
    unordered_map<string, int> word_cnt;

    while (N--) {
        cin >> s;

        word_cnt[s]++;

        string alias = "";
        bool found_alias = false;

        for (int i = 1; i <= s.size(); i++) {
            string prefix(s.begin(), s.begin() + i);
            auto it = prefixes.find(prefix);

            if (!found_alias && it == prefixes.end()) {
                alias = prefix;
                found_alias = true;
            }
            
            prefixes.insert(prefix);
        }

        if (!found_alias) {
            alias = s;
            if (word_cnt[s] > 1) alias += to_string(word_cnt[s]);
        }

        cout << alias << '\n';
    } 

    return 0;
}