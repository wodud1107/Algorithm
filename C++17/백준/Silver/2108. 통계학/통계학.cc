#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

int mode(vector<int> num){
    unordered_map<int, int> freq;

    for (int n : num){
        freq[n]++;
    }

    int max = 0;
    for (auto& [n, count] : freq){
        if (count > max){
            max = count;
        }
    }

    vector<int> modes;
    for (auto& [n, count] : freq){
        if (count == max) modes.push_back(n);
    }

    sort(modes.begin(), modes.end());

    if (modes.size() > 1) return modes[1];
    else return modes[0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> num;
    int sum = 0;
    for (int i = 0; i < N; i++){
        int x; cin >> x;

        num.push_back(x);
        sum += x;
    }

    sort(num.begin(), num.end());

    double avg = (double) sum / N;
    cout << (int) round(avg) << '\n';
    cout << num.at(N / 2) << '\n';
    cout << mode(num) << '\n';
    cout << *(num.end()-1) - (*num.begin()) << '\n';

    return 0;
}