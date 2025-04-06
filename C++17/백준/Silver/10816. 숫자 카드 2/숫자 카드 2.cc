#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    unordered_map<int, int> card;
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;

        card[x]++;
    }

    int M;
    cin >> M;

    while (M--){
        int x;
        cin >> x;

        cout << card[x] << ' ';
    }
    cout << '\n';

    return 0;
}