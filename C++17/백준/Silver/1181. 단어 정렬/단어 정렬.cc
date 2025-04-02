#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<string> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](const string &a, const string &b){
        if (a.length() != b.length()) return a.length() < b.length();
        return a < b;
    });

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (const string &s : arr){
        cout << s << '\n';
    }

    return 0;
}