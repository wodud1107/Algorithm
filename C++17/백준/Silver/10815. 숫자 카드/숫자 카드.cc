#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int x;
    unordered_set<int> card;
    for (int i = 0; i < N; i++){
        cin >> x;
        card.insert(x);
    }

    int M;
    cin >> M;
    while (M--){
        cin >> x;
        cout << card.count(x) << ' ';
    }
    
    return 0;
}