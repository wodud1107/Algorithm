#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    unordered_set<string> listen;
    while (N--){
        string s;
        cin >> s;
        listen.insert(s);
    }

    unordered_set<string> dbj;
    while (M--){
        string s;
        cin >> s;

        if (listen.count(s)){
            dbj.insert(s);
        }
    }

    vector<string> print(dbj.begin(), dbj.end());
    sort(print.begin(), print.end());

    cout << print.size() << '\n';
    for (string name : print) {
        cout << name << '\n';
    }

    return 0;
}