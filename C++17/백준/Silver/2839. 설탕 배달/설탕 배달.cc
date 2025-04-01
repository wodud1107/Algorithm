#include <iostream>

using namespace std;
int main(){
    int N;
    cin >> N;

    int answer = N / 5;
    int tmp = N % 5;
    switch (tmp) {
        case 1:
            if (N > 5) answer += 1;
            else answer = -1;
            break;
        case 2:
            if (N > 11) answer += 2;
            else answer = -1;
            break;
        case 3:
            if (N > 3) answer += 1;
            else answer = 1;
            break;
        case 4:
            if (N > 8) answer += 2;
            else answer = -1;
            break;
        default:
            break;
    }

    cout << answer << endl;

    return 0;
}