#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> global_info;
vector<vector<int>> adjacency;
int max_sheep = 0;

void dfs(int sheep, int wolves, vector<int> next_nodes) {
    max_sheep = max(max_sheep, sheep);
    
    for (int i = 0; i < next_nodes.size(); i++) {
        int next_node = next_nodes[i];
        
        int next_sheep = sheep;
        int next_wolves = wolves;
        
        if (global_info[next_node] == 0) {
            next_sheep++;
        } else {
            next_wolves++;
        }
        
        if (next_wolves >= next_sheep) {
            continue;
        }
        
        vector<int> new_next_nodes;
        for(int j = 0; j < next_nodes.size(); j++) {
            if(i == j) continue;
            new_next_nodes.push_back(next_nodes[j]);
        }
        
        for (int child : adjacency[next_node]) {
            new_next_nodes.push_back(child);
        }
        
        dfs(next_sheep, next_wolves, new_next_nodes);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    global_info = info;
    adjacency.resize(info.size());
    
    for (const auto& edge : edges) {
        adjacency[edge[0]].push_back(edge[1]);
    }
    
    vector<int> initial_next_nodes;
    for (int child : adjacency[0]) {
        initial_next_nodes.push_back(child);
    }
    
    dfs(1, 0, initial_next_nodes);
    
    return max_sheep;
}