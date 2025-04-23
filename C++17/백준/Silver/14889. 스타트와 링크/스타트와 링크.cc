#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int N, min_res = INT_MAX;
int R[21];
int C[21];
bool visited[21];

void dfs(int pos, int depth, int val){
    if (depth == N / 2){
        min_res = min(min_res, abs(val));
        return;
    }

    for (int i = pos; i < N; i++){
        if (!visited[i]){
            visited[i] = 1;
            dfs(i + 1, depth + 1, val - R[i] - C[i]);
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> N;

    int sum = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int x; cin >> x;
            sum += x;
            R[i] += x;
            C[j] += x;
        }
    }

    dfs(0, 0, sum);
    cout << min_res << '\n';
    
    return 0;
}