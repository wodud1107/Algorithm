#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    deque<int> deque;

    while (N--){
        int cmd; cin >> cmd;

        switch (cmd){
        case 1:
            int x; cin >> x;
            deque.push_front(x);
            break;
        case 2:
            int y; cin >> y;
            deque.push_back(y);
            break;
        case 3:
            if (deque.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << deque.front() << '\n';
                deque.pop_front();
            }
            break;
        case 4:
            if (deque.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << deque.back() << '\n';
                deque.pop_back();
            }
            break;
        case 5:
            cout << deque.size() << '\n';
            break;
        case 6:
            cout << deque.empty() << '\n';
            break;
        case 7:
            if (deque.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << deque.front() << '\n';
            }
            break;
        case 8:
            if (deque.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << deque.back() << '\n';
            }
            break;
        default:
            break;
        }
    }

    return 0;
}