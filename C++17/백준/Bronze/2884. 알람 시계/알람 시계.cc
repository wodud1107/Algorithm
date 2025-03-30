#include <iostream>

int main(){
    int H, M;
    std::cin >> H >> M;
    if (M < 45) {
        M += 15;
        if (H == 0){
            H = 23;
        } else {
            H -= 1;
        }
    } else {
        M -= 45;
    }
    std::cout << H << ' ' << M << std::endl;
    return 0;
}