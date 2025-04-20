#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N; cin >> N;

    vector<int> factor;
    for (int i = 0; i < N; i++){
        int x; cin >> x;

        factor.push_back(x);
    }

    sort(factor.begin(), factor.end());

    cout << *factor.begin() * (*(factor.end() - 1)) << '\n';
    
    return 0;
}