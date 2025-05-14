#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int,int>> meet;
    for (int i = 0; i < N; i++){
        int start, end;
        cin >> start >> end;
        meet.push_back({end, start});
    }

    sort(meet.begin(), meet.end());

    int cnt = 0, prev_end = -1;
    for (auto& [e, s] : meet){
        if (s >= prev_end){
            cnt++;
            prev_end = e;
        }
    }

    cout << cnt << '\n';

    return 0;
}