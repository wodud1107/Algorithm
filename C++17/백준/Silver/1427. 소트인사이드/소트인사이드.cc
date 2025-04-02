#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int N;
    cin >> N;

    vector<int> arr;
    while (N){
        arr.push_back(N % 10);
        N /= 10;
    }

    sort(arr.begin(), arr.end(), greater<int>());

    for (int i = 0; i < arr.size(); i++){
        cout << arr.at(i);
    }
    
    return 0;
}