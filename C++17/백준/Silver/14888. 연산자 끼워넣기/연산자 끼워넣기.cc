#include <iostream>
#include <climits>
using namespace std;

int N, min_res = INT_MAX, max_res = INT_MIN;
int num[101];
int op[4];

void dfs(int depth, int val);

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        int x; cin >> x;
        num[i] = x;
    }

    for(int i = 0; i < 4; i++){
        int x; cin >> x;
        op[i] = x;
    }

    dfs(1, num[0]);
    cout << max_res << '\n' << min_res << '\n';

    return 0;
}

void dfs(int depth, int val){
    if (depth == N){
        max_res = max(max_res, val);
        min_res = min(min_res, val);
        return;
    }

    for (int i = 0; i < 4; i++){
        if (op[i]){
            op[i]--;

            switch(i){
                case 0:
                    dfs(depth + 1, val + num[depth]);
                    break;
                case 1:
                    dfs(depth + 1, val - num[depth]);
                    break;
                case 2:
                    dfs(depth + 1, val * num[depth]);
                    break;
                case 3:
                    dfs(depth + 1, val / num[depth]);
                    break;
                default:
                    break;
            }

            op[i]++;
        }
    }
}