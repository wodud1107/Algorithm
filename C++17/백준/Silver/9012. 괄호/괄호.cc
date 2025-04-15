#include <iostream>
#include <stack>
using namespace std;

string solve(string x);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--){
        string x; cin >> x;

        cout << solve(x) << '\n';
    }

    return 0;
}

string solve(string x){
    stack<char> s;

    for (char c : x){
        if (c == ')'){
            if (s.empty()) {
                return "NO";
            }
            else s.pop();
        }
        else s.push(c);
    }
    
    if (s.empty()) return "YES";
    else return "NO";
}