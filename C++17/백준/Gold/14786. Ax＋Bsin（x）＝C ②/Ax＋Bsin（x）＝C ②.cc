#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);

    double s = 0, e = 100000;
    while (e - s > 1e-9) {
        double mid = (s + e) / 2;
        double val = A * mid + B * sin(mid);
        if (val * val > C * C)
            e = mid;
        else if (val * val < C * C)
            s = mid;
        else break;
    }

    printf("%.15lf\n", e);

    return 0;
}