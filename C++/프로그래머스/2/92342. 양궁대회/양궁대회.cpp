#include <string>
#include <vector>

using namespace std;

vector<int> answer = {-1};
int max_diff = 0;

void calculate_score(const vector<int>& ryan, const vector<int>& apeach, int& ryan_score, int& apeach_score) {
    ryan_score = 0;
    apeach_score = 0;
    
    for (int i = 10; i >= 0; i--) {
        if (ryan[i] == 0 && apeach[i] == 0) continue;
        
        if (ryan[i] > apeach[i]) {
            ryan_score += (10 - i);
        } else {
            apeach_score += (10 - i);
        }
    }
}

bool is_better(const vector<int>& ryan) {
    for (int i = 10; i >= 0; i--) {
        if (ryan[i] > answer[i]) return true;
        if (ryan[i] < answer[i]) return false;
    }
    return (false);
}

void dfs(int index, int arrows_left, vector<int>& ryan, vector<int>& apeach) {
    if (index == 11 || arrows_left == 0) {
        if (arrows_left) {
            ryan[10] += arrows_left;
        }
        
        int ryan_score, apeach_score;
        calculate_score(ryan, apeach, ryan_score, apeach_score);
        
        int diff = ryan_score - apeach_score;
        if (diff > 0) {
            if (diff > max_diff) {
                max_diff = diff;
                answer = ryan;
            } else if (diff == max_diff) {
                if (is_better(ryan)) {
                    answer = ryan;
                }
            }
        }
        
        if (arrows_left) {
            ryan[10] -= arrows_left;
        }
        
        return;
    }
    
    int arrows_to_win = apeach[index] + 1;
    if (arrows_left >= arrows_to_win) {
        ryan[index] = arrows_to_win;
        dfs(index + 1, arrows_left - arrows_to_win, ryan, apeach);
        ryan[index] = 0;
    }
    
    dfs(index + 1, arrows_left, ryan, apeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11, 0);
    dfs(0, n, ryan, info);
    return answer;
}