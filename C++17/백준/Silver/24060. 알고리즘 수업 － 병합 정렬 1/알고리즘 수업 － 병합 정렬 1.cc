#include <iostream>
#include <vector>
using namespace std;

int cnt = 0, K;

void merge(int A[], int l, int m, int r){
    vector<int> tmp;
    int i = l, j = m + 1;

    while (i <= m && j <= r){
        if (A[i] <= A[j]){
            tmp.push_back(A[i++]);
        } else {
            tmp.push_back(A[j++]);
        }
    }
    while (i <= m) tmp.push_back(A[i++]);
    while (j <= r) tmp.push_back(A[j++]);

    for (int k = l; k <= r; k++){
        cnt++;
        A[k] = tmp[k - l];
        if (cnt == K) cout << A[k] << '\n';
    }
}

void mergeSort(int A[], int l, int r){
    if(l >= r) return;

    int m = (l + r) / 2;
    mergeSort(A, l, m);
    mergeSort(A, m+1, r);
    merge(A, l, m, r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N >> K;

    int A[N];
    for (int i = 0; i < N; i++){
        int x; cin >> x;
        A[i] = x;
    }

    mergeSort(A, 0, N-1);

    if (cnt < K) cout << -1 << '\n';

    return 0;
}