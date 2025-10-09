#include <string>
#include <vector>
#include <sstream>

using namespace std;

int parent[2501];
string values[2501];

int to_1d_idx(int r, int c) {
    return (r - 1) * 50 + c;    
}

int find_root(int idx) {
    if (parent[idx] == idx) {
        return idx;
    }
    return parent[idx] = find_root(parent[idx]);
}

void union_sets(int idx1, int idx2) {
    int root1 = find_root(idx1);
    int root2 = find_root(idx2);
    
    if (root1 != root2) {
        string& val1 = values[root1];
        string& val2 = values[root2];
        
        if (!val1.empty()) {
            parent[root2] = root1;
        } else {
            parent[root2] = root1;
            values[root1] = val2;
        }
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for (int i = 1; i <= 2500; i++) {
        parent[i] = i;
        values[i] = "";
    }
    
    for (const string& command : commands) {
        stringstream ss(command);
        string cmd;
        ss >> cmd;
        
        if (cmd == "UPDATE") {
            string arg1, arg2, value;
            ss >> arg1 >> arg2;
            
            if (ss >> value) {
                int r = stoi(arg1);
                int c = stoi(arg2);
                int root = find_root(to_1d_idx(r, c));
                values[root] = value;
            } else {
                for (int i = 1; i <= 2500; i++) {
                    int root = find_root(i);
                    if (values[root] == arg1) {
                        values[root] = arg2;
                    }
                }
            } 
        } else if (cmd == "MERGE") {
                int r1, c1, r2, c2;
                ss >> r1 >> c1 >> r2 >> c2;
                int idx1, idx2;
                idx1 = to_1d_idx(r1, c1);
                idx2 = to_1d_idx(r2, c2);
                if (idx1 != idx2) {
                    union_sets(idx1, idx2);
                }
        } else if (cmd == "UNMERGE") {
            int r, c;
            ss >> r >> c;
            int idx = to_1d_idx(r, c);
            int root = find_root(idx);
            string root_value = values[root];

            vector<int> cells_to_unmerge;
            for (int i = 1; i <= 2500; i++) {
                if (find_root(i) == root) {
                    cells_to_unmerge.push_back(i);
                }
            }

            for (int cell_idx : cells_to_unmerge) {
                parent[cell_idx] = cell_idx;
                values[cell_idx] = "";
            }
            values[idx] = root_value;
        } else if (cmd == "PRINT") {
            int r, c;
            ss >> r >> c;

            int root = find_root(to_1d_idx(r, c));
            if (values[root].empty()) {
                answer.push_back("EMPTY");
            } else {
                answer.push_back(values[root]);
            }
        }
    }
    
    return answer;
}