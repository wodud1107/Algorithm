#include <string>
#include <vector>

using namespace std;

int global_k;
int answer = 0;

void dfs(int cnt, vector<vector<int>>& dungeons, vector<bool>& visited) {
    if (answer < cnt) answer = cnt;
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i]) continue;
        
        if (global_k >= dungeons[i][0]) {
            global_k -= dungeons[i][1];
            visited[i] = true;
            dfs(cnt + 1, dungeons, visited);
            global_k += dungeons[i][1];
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    global_k = k;
    vector<bool> visited(dungeons.size(), false);
    dfs(0, dungeons, visited);
    return answer;
}