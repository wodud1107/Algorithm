#include <iostream>

int main() {
    int X, N, a, b;
    std::cin >> X >> N;

    int sum=0;
    while (N-- > 0) {
        std::cin >> a >> b;
        sum += a * b;
        if (sum > X) break;
    }
    if (sum == X) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}