#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> note;
    while (N--){
        string s;
        cin >> s;

        if (s.length() >= M) note[s]++;
    }

    vector<pair<string, int>> v(note.begin(), note.end());
    sort(v.begin(), v.end(), [](const auto& a, const auto& b){
        if (a.second != b.second) return a.second > b.second;
        if (a.first.length() != b.first.length()) return a.first.length() > b.first.length();
        return a.first < b.first;
    });
    
    for (int i = 0; i < v.size(); i++){
        cout << v[i].first << '\n';
    }

    return 0;
}