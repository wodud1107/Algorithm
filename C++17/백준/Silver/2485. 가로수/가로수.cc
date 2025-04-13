#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int N;
    cin >> N;

    vector<int> interval;
    int prior; cin >> prior;
    for (int i = 1; i < N; i++){
        int x;
        cin >> x;
        interval.push_back(x - prior);

        prior = x;
    }

    int g = gcd(interval.at(0), interval.at(1));
    for (int i = 2; i < interval.size(); i++){
        g = gcd(g, interval.at(i));
    }
    
    int cnt = 0;
    for (int i = 0; i < interval.size(); i++){
        cnt += interval.at(i) / g - 1;
    }

    cout << cnt;

    return 0;
}