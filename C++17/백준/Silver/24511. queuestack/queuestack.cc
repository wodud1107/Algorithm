#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    deque<int> dq;

    bool A[N];
    for (int i = 0; i < N; i++){
        int x; cin >> x;
        A[i] = x;
    }

    for (int i = 0; i < N; i++){
        int x; cin >> x;
        if (!A[i]) dq.push_back(x);
    }

    int M; cin >> M;
    while (M--){
        int x; cin >> x;

        dq.push_front(x);
        cout << dq.back() << ' ';
        dq.pop_back();
    }

    return 0;
}