#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int N, k;
    cin >> N >> k;

    int arr[N];
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);
    cout << arr[N-k];

    return 0;
}