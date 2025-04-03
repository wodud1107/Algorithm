#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair<int, string>> member(N);
    for (int i = 0; i < N; i++){
        cin >> member.at(i).first >> member.at(i).second;
    }

    stable_sort(member.begin(), member.end(), [](const pair<int,string> &a, const pair<int,string> &b){
        return a.first < b.first;
    });

    for (int i = 0; i < N; i++){
        cout << member.at(i).first << ' ' << member.at(i).second << '\n';
    }

    return 0;
}