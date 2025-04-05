#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    unordered_set<string> list;

    while (N--){
        string s1, s2;
        cin >> s1 >> s2;
        if (s2 == "enter"){
            list.insert(s1);
        } else {
            list.erase(s1);
        }
    }

    vector<string> left(list.begin(), list.end());
    sort(left.begin(), left.end(), greater<string>());

    for (string name : left){
        cout << name << '\n';
    }

    return 0;
}