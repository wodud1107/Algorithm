#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, P, Q;
    cin >> N >> P >> Q;

    int A[N], B[N];
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    for (int i = 0; i < N; i++){
        cin >> B[i];
    }

    int C[N];
    for (int i = 0; i < N; i++){
        int pick = abs(P - Q);

        if (A[i] == B[i]){
            C[i] = 0;
            continue;
        }
        else if (P == Q) {
            cout << "NO" << '\n';
            return 0;
        }

        if (A[i] > B[i]){
            if (P > Q){
                cout << "NO" << '\n';
                return 0;
            }
            
            int diff = A[i] - B[i];
    
            if (diff % pick != 0){
                cout << "NO" << '\n';
                return 0;
            }
            else {
                C[i] = diff / pick;
            }
        } else{
            if (P < Q){
                cout << "NO" << '\n';
                return 0;
            }

            int diff = B[i] - A[i];
    
            if (diff % pick != 0){
                cout << "NO" << '\n';
                return 0;
            }
            else {
                C[i] = diff / pick;
            }
        }
    }

    cout << "YES" << '\n';
    for (int i = 0; i < N; i++) cout << C[i] << ' ';
    cout << '\n';

    return 0;
}