#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;

    stack<int> s;

    while (K--){
        int x; cin >> x;
        
        if (!x) s.pop();
        else s.push(x);
    }

    int sum = 0;
    while (!s.empty()){
        sum += s.top();
        s.pop();
    }

    cout << sum << '\n';

    return 0;
}