#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);

    double s = 0, e = 100000;
    while (s <= e) {
        double mid = (s + e) / 2;
        double val = A * mid + B * sin(mid);
        if (val * val > C * C)
            e = mid - 1e-9;
        else if (val * val < C * C)
            s = mid + 1e-9;
        else break;
    }

    printf("%.15lf\n", e);

    return 0;
}