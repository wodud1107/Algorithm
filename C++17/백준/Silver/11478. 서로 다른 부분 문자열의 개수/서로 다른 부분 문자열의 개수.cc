#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    string S;
    cin >> S;

    set<string> set;
    for (int i = 0; i < S.length(); i++){
        for (int j = 1; j <= S.length() - i; j++){
            set.insert(S.substr(i, j));
        }
    }
    
    cout << set.size() << '\n';

    return 0;
}