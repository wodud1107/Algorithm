#include <iostream>

using namespace std;
int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int det = a * e - b * d;
    int x = (e * c - b * f) / det;
    int y = (-d * c + a * f) / det;

    cout << x << ' ' << y << endl;

    return 0;
}