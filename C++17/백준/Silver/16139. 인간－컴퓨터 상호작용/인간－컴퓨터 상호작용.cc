#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    int q;
    cin >> q;

    int prefix[26][S.length() + 1];
    memset(prefix, 0, sizeof(prefix));
    for (int i = 1; i <= S.length(); i++){
        for (int j = 0; j < 26; j++){
            prefix[j][i] = prefix[j][i - 1];
        }
        prefix[S[i - 1] - 'a'][i]++;
    }

    while(q--){
        char alpha;
        int l, r;
        cin >> alpha >> l >> r;

        cout << prefix[alpha - 'a'][r + 1] - prefix[alpha - 'a'][l] << '\n';
    }

    return 0;
}