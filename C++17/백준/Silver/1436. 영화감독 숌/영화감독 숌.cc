#include <iostream>

using namespace std;
int main(){
    int N;
    cin >> N;

    int cnt = 0;
    for (int i = 666; cnt <= 10000; i++) {
        int tmp = i;
        while (tmp > 665) {
            int check = tmp % 1000;
            
            if (check == 666){
                cnt ++;
                break;
            }
            tmp /= 10;
        }

        if (cnt == N) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}