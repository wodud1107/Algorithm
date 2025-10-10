#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int convert_to_days(string date) {
    int years = stoi(date.substr(0, 4));
    int months = stoi(date.substr(5, 2));
    int days = stoi(date.substr(8, 2));
    return (years * 12 + months) * 28 + days;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int _today = convert_to_days(today);
    
    map<string, int> term_expiration;
    for (const string& term : terms) {
        stringstream ss(term);
        string term_name, term_exp;
        ss >> term_name >> term_exp;
        
        int term_days = stoi(term_exp) * 28;
        term_expiration[term_name] = term_days;
    }
    
    for (int i = 0; i < privacies.size(); i++) {
        stringstream ss(privacies[i]);
        string date, term;
        ss >> date >> term;
        
        int regist_days = convert_to_days(date);
        if (_today - regist_days >= term_expiration[term]) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}