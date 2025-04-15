#include <iostream>
#include <stack>
using namespace std;

string balance(string str);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while(1){
        getline(cin, line);

        if (line == ".") break;

        cout << balance(line) << '\n';
    }
    return 0;
}

string balance(string str){
    stack<char> s;

    for (char c : str){
        if (c == '(' || c == '[') s.push(c);
        else if (c == ')'){
            if (s.empty() || s.top() != '(') return "no";
            else s.pop();
        } else if (c == ']'){
            if (s.empty() || s.top() != '[') return "no";
            else s.pop();
        }
    }

    if (s.empty()) return "yes";
    else return "no";
}