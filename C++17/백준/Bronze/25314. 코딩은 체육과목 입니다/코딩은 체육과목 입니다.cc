#include <iostream>

int main() {
    int N;
    std::cin >> N;
    for (int i=0; i<N; i+=4) {
        std::cout << "long ";
    }
    std::cout << "int";
    return 0;
}