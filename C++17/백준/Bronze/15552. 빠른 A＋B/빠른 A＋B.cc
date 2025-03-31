#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, A, B;
    std::cin >> T;
    while (T-- > 0) {
        std::cin >> A >> B;
        std::cout << A + B << '\n';
    }

    return 0;
}