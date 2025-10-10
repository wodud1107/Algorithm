#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> id_to_idx;
    for (int i = 0; i < id_list.size(); i++) {
        id_to_idx[id_list[i]] = i;
    }
    
    map<string, set<string>> reported_ids;
    for (const string& rep : report) {
        stringstream ss(rep);
        string reporter, reported;
        ss >> reporter >> reported;
        
        reported_ids[reported].insert(reporter);
    }
    
    for (auto const& [reported, reporters] : reported_ids) {
        if (reporters.size() >= k) {
            for (const string& reporter_id : reporters) {
                answer[id_to_idx[reporter_id]]++;
            }
        }
    }
    
    return answer;
}