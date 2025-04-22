#include <iostream>
using namespace std;

int N, M;
bool visited[9];
int num[9];

void dfs(int depth);

int main(){
    cin >> N >> M;
    dfs(0);
    return 0;
}

void dfs(int depth){
    if (depth == M){
        for (int i = 0; i < M; i++){
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            visited[i] = 1;
            num[depth] = i + 1;
            dfs(depth + 1);
            visited[i] = 0;
        }
    }
}