#include <iostream>
#include <deque>
using namespace std;

int main(){
    int N; cin >> N;

    deque<pair<int, int>> balloon;
    for (int i = 1; i <= N; i++){
        int x; cin >> x;
        balloon.push_back({i, x});
    }

    while(!balloon.empty()){
        auto [idx, move] = balloon.front();
        balloon.pop_front();
        cout << idx << ' ';

        if (balloon.empty()) break;

        if (move > 0){
            for (int i = 1; i < move; i++){
                balloon.push_back(balloon.front());
                balloon.pop_front();
            }
        } else {
            for (int i = 0; i > move; i--){
                balloon.push_front(balloon.back());
                balloon.pop_back();
            }
        }
    }

    return 0;
}