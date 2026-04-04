#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int> left_max;
    priority_queue<int, vector<int>, greater<int>> right_min;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        
        if (left_max.size() == right_min.size()) {
            left_max.push(a);
        } else {
            right_min.push(a);
        }

        if (!right_min.empty() && left_max.top() > right_min.top()) {
            int x = left_max.top(); left_max.pop();
            int y = right_min.top(); right_min.pop();
            left_max.push(y);
            right_min.push(x);
        }

        cout << left_max.top() << '\n';
    }

    return 0;
}