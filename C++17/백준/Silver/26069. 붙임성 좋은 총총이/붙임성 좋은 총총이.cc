#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    set<string> dance;
    dance.insert("ChongChong");

    while (N--){
        string s1, s2;
        cin >> s1 >> s2;

        if (dance.count(s1)) dance.insert(s2);
        else if (dance.count(s2)) dance.insert(s1);
    }

    cout << dance.size() << '\n';

    return 0;
}