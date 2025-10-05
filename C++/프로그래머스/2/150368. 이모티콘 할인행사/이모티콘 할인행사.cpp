#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_subscribers = 0;
int max_sales = 0;
vector<vector<int>> glob_users;
vector<int> glob_emoticons;

void dfs(int idx, vector<int>& discounts) {
    if (idx == glob_emoticons.size()) {
        int current_subscribers = 0;
        int current_sales = 0;
        
        for (const auto& user : glob_users) {
            int user_ratio = user[0];
            int user_price = user[1];
            int total = 0;
            
            for (int i = 0; i < glob_emoticons.size(); i++) {
                if (discounts[i] >= user_ratio) {
                    total += glob_emoticons[i] * (100 - discounts[i]) / 100;
                }
            }
            
            if (total >= user_price) {
                current_subscribers++;
            } else {
                current_sales += total;
            }
        }
        
        if (current_subscribers > max_subscribers) {
            max_subscribers = current_subscribers;
            max_sales = current_sales;
        } else if (current_subscribers == max_subscribers) {
            max_sales = max(max_sales, current_sales);
        }
        return;
    }
    
    for (int rate = 10; rate <= 40; rate+= 10) {
        discounts[idx] = rate;
        dfs(idx + 1, discounts);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    glob_users = users;
    glob_emoticons = emoticons;
    
    vector<int> discounts(emoticons.size());
    dfs(0, discounts);
    
    vector<int> answer;
    answer.push_back(max_subscribers);
    answer.push_back(max_sales);
    return answer;
}