#include <string>
#include <vector>

using namespace std;

int n_global, m_global, r_global, c_global, k_global;
string answer = "";
bool is_found = false;
char move_char[] = {'d', 'l', 'r', 'u'};
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

int calculate_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
    
void dfs(int x, int y, string current_path) {
    if (is_found) {
        return;
    }
    
    int remaining_moves = k_global - current_path.length();
    int distance_to_end = calculate_distance(x, y, r_global, c_global);
    
    if (remaining_moves < distance_to_end || (remaining_moves - distance_to_end) % 2 != 0) {
        return;
    }
    
    if (current_path.length() == k_global) {
        if (x == r_global && y == c_global) {
            answer = current_path;
            is_found = true;
        }
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if (next_x >= 1 && next_x <= n_global && next_y >= 1 && next_y <= m_global) {
            dfs(next_x, next_y, current_path + move_char[i]);
            if (is_found) return;
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    n_global = n;
    m_global = m;
    r_global = r;
    c_global = c;
    k_global = k;
    is_found = false;
    answer = "";
    
    int init_dist = calculate_distance(x, y, r, c);
    if (k < init_dist || (k - init_dist) % 2 != 0) {
        return "impossible";
    }
    
    dfs(x, y, "");
    
    return answer.empty() ? "impossible" : answer;
}