#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    set<string> hi;

    while (N--){
        string s;
        cin >> s;

        if (s == "ENTER"){
            cnt += hi.size();
            hi.clear();
        } else{
            hi.insert(s);
        }
    }

    cout << cnt + hi.size() << '\n';

    return 0;
}