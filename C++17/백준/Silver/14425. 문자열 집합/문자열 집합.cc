#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    unordered_set<string> str;
    for (int i = 0; i < N; i++){
        string s;
        cin >> s;
        str.insert(s);
    }

    int cnt = 0;
    while (M--){
        string s;
        cin >> s;
        cnt += str.count(s);
    }

    cout << cnt << '\n';

    return 0;
}