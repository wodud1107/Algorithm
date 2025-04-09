#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    unordered_set<int> setA, setB;
    for (int i = 0; i < A; i++){
        int x;
        cin >> x;
        setA.insert(x);
    }

    for (int i = 0; i < B; i++){
        int x;
        cin >> x;
        setB.insert(x);
    }

    int dup = 0;
    for (int x : setA){
        if (setB.count(x)) dup++;
    }

    cout << A + B - 2 * dup << '\n';

    return 0;
}