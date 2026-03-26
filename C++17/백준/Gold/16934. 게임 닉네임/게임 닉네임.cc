#include <iostream>
#include <string>
using namespace std;

int N;
string s;
const int MAX_NODES = 1000005;
const int ROOT = 1;
int nxt[MAX_NODES][26];
int end_cnt[MAX_NODES];
int unused = 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    while (N--) {
        cin >> s;

        int curr = ROOT;
        string alias = "";
        bool found_alias = false;

        for (char c: s) {
            int idx = c - 'a';
            
            if (!found_alias)
                alias += c;

            if (nxt[curr][idx] == 0) {
                if (!found_alias) found_alias = true;
                nxt[curr][idx] = unused++;
            }

            curr = nxt[curr][idx];
        }
        end_cnt[curr]++;

        if (!found_alias) {
            alias = s;
            if (end_cnt[curr] > 1) alias += to_string(end_cnt[curr]);
        }

        cout << alias << '\n';
    } 

    return 0;
}