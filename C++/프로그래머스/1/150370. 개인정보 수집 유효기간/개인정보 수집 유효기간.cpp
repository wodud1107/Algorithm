#include <string>
#include <vector>
#include <map>

using namespace std;

int dateToDays(string date_str) {
    int year = stoi(date_str.substr(0, 4));
    int month = stoi(date_str.substr(5, 2));
    int day = stoi(date_str.substr(8, 2));
    
    return (year * 12 * 28) + (month * 28) + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int today_days = dateToDays(today);
    
    map<char, int> term_map;
    for (const string& term : terms) {
        size_t pos = term.find(' ');
        char type = term[0];
        
        int duration_month = stoi(term.substr(pos + 1));
        
        term_map[type] = duration_month;
    }
    
    for (int i = 0; i < privacies.size(); ++i) {
        const string& privacy = privacies[i];
        
        size_t pos = privacy.find(' ');
        
        string collection_date_str = privacy.substr(0, pos);
        char term_type = privacy[pos + 1];
        
        int collection_days = dateToDays(collection_date_str);
        int duration_months = term_map[term_type];
        int expiration_days = collection_days + (duration_months * 28);
        
        if (today_days >= expiration_days) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}