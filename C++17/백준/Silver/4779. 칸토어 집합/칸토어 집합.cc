#include <iostream>
#include <cmath>
using namespace std;

string Cantor(int length){
    int part = length / 3;

    if (length == 1) return "-";

    string left = Cantor(part);
    string mid(part, ' ');
    string right = Cantor(part);

    return left + mid + right;
}

int main(){
    int N;
    while (cin >> N){
        int len = pow(3, N);

        cout << Cantor(len) << '\n';
    }

    return 0;
}