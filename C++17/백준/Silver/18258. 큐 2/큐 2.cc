#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;

    queue<int> q;
    while (N--){
        string cmd; cin >> cmd;

        if (cmd == "push"){
            int x; cin >> x;

            q.push(x);
        } else if (cmd == "pop"){
            if (q.empty()){
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (cmd == "size"){
            cout << q.size() << '\n';
        } else if (cmd == "empty"){
            cout << q.empty() << '\n';
        } else if (cmd == "front"){
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        } else {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;
}