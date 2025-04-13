#include <iostream>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main(){
    int numer1, numer2, denom1, denom2;
    cin >> numer1 >> denom1 >> numer2 >> denom2;

    int b = lcm(denom1, denom2);
    int a = numer1 * (b / denom1) + numer2 * (b / denom2);

    int g = gcd(a, b);
    cout << a / g << ' ' << b / g << '\n';

    return 0;
}

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}