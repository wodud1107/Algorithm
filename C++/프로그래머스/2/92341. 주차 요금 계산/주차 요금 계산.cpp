#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>

using namespace std;

int time_to_minutes(string time_str) {
    int hours = stoi(time_str.substr(0, 2));
    int minutes = stoi(time_str.substr(3, 2));
    return hours * 60 + minutes;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> entered;
    map<string, int> total_parked;
    for (const string& record : records) {
        stringstream ss(record);
        string time, num, inout;
        ss >> time >> num >> inout;
        
        int time_in_minutes = time_to_minutes(time);
        
        if (inout == "IN") {
            entered[num] = time_in_minutes;
        } else {
            int enter_time = entered[num];
            entered.erase(num);
            
            int parked_time = time_in_minutes - enter_time;
            total_parked[num] += parked_time;
        }
    }
    
    int final_time = time_to_minutes("23:59");
    for (auto const& [num, enter_time] : entered) {
        int parked_time = final_time - enter_time;
        total_parked[num] += parked_time;
    }
    
    for (auto const& [num, total_time] : total_parked) {
        int base_time = fees[0];
        int base_fee = fees[1];
        int unit_time = fees[2];
        int unit_fee = fees[3];
        
        if (total_time <= base_time) {
            answer.push_back(base_fee);
        } else {
            int extra_time = ceil((double)(total_time - base_time) / unit_time);
            int final_fee = base_fee + extra_time * unit_fee;
            answer.push_back(final_fee);
        }
    }
    
    
    return answer;
}