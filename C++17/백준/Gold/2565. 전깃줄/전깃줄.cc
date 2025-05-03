#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    map<int, int> line;
    int x, y;
    for (int i = 0; i < N; i++){
        cin >> x >> y;
        line.insert({x, y});
    }

    vector<int> connect;
    for (auto& [key, value] : line){
        auto it = lower_bound(connect.begin(), connect.end(), value);
        if (it == connect.end()){
            connect.push_back(value);
        } else {
            *it = value;
        }
    }

    cout << N - connect.size() << '\n';

    return 0;
}