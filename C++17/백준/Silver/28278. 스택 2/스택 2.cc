#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    stack<int> stack;
    while (N--){
        int cmd; cin >> cmd;

        switch (cmd){
        case 1:
            int X; cin >> X;
            stack.push(X);
            break;
        case 2:
            if (stack.empty()){
                cout << -1 << '\n';
            } else {
                cout << stack.top() << '\n';
                stack.pop();
            }
            break;
        case 3:
            cout << stack.size() << '\n';
            break;
        case 4:
            cout << stack.empty() << '\n';
            break;
        case 5:
            if (stack.empty()){
                cout << -1 << '\n';
            } else {
                cout << stack.top() << '\n';
            }
            break;
        default:
            break;
        }

    }
    return 0;
}