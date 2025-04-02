#include <iostream>

int count[10001];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, x;
    std::cin >> N;

    for (int i = 0; i < N; i++){
        std::cin >> x;
        count[x]++;
    }

    for (int i = 0; i < 10001; i++){
        while(count[i]--){
            std::cout << i << '\n';
        }
    }

    return 0;
}