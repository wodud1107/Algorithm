#include <iostream>
#include <iomanip>

int main(){
    double a, b;
    std::cin >> a >> b;
    std::cout << std::fixed << std::setprecision(10) << a/b << std::endl;
    return 0;
}