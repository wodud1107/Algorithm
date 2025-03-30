#include <iostream>

int main() {
    int A, B, T;
    std::cin >> T;
    while (T-- > 0) {
        std::cin >> A >> B;
        std::cout << A + B << std::endl;
    }
    return 0;
}