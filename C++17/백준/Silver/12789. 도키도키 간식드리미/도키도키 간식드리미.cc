#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int N; cin >> N;

    stack<int> side;
    stack<int> receive;

    for (int i = 0; i < N; i++){
        int x; cin >> x;

        if (!side.empty() && side.top() < x){
            if (!receive.empty() && receive.top() > side.top()){
                cout << "Sad\n";
                return 0;
            } else {
                receive.push(side.top());
                side.pop();
            }
        }
        side.push(x);
    }

    if (!receive.empty() && receive.top() > side.top()) cout << "Sad\n";
    else cout << "Nice\n";

    return 0;
}