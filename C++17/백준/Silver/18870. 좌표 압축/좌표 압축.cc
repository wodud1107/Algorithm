#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> num(N);
    vector<int> copy(N);
    for (int i  = 0; i < N; i++){
        cin >> num.at(i);
        copy.at(i)=num.at(i);
    }

    sort(copy.begin(), copy.end());

    copy.erase(unique(copy.begin(), copy.end()), copy.end());

    unordered_map<int, int> rank;
    for (int i = 0; i < copy.size(); i++){
        rank[copy[i]] = i;
    }

    for (int x : num){
        cout << rank[x] << ' ';
    }
    cout << '\n';

    return 0;
}