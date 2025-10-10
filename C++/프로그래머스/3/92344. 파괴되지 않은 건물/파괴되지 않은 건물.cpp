#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> delta(n + 1, vector<int>(m + 1, 0));
    
    for (const auto& s : skill) {
        int type = s[0];
        int r1 = s[1], c1 = s[2];
        int r2 = s[3], c2 = s[4];
        int degree = s[5];
        
        int value = (type == 1) ? -degree : degree;
        
        delta[r1][c1] += value;
        delta[r1][c2 + 1] -= value;
        delta[r2 + 1][c1] -= value;
        delta[r2 + 1][c2 + 1] += value;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            delta[i][j] += delta[i][j - 1];
        }
    }
    
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            delta[i][j] += delta[i - 1][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] + delta[i][j] > 0) {
                answer++;
            }
        }
    }
    return answer;
}