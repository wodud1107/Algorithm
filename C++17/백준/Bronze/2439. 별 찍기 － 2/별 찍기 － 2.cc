#include <iostream>

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = N-1; j > i; j--) {
            std::cout << ' ';
        }
        for (int j = 0; j <= i; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    return 0;
}