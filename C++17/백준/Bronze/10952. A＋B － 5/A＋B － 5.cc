#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    while (A || B) {
        std::cout << A + B << std::endl;
        std::cin >> A >> B;
    }

    return 0;
}