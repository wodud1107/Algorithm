#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a == b) {
        if (b == c){
            std::cout << 10000 + a * 1000 << std::endl;
        } else {
            std::cout << 1000 + a * 100 << std::endl;
        }
    } else if (b == c || a == c) {
        std::cout << 1000 + c * 100 << std::endl;
    } else {
        std::cout << std::max(a, std::max(b, c)) * 100 << std::endl;
    }
    return 0;
}