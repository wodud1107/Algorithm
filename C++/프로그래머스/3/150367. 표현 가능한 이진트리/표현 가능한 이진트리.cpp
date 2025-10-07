#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_valid(const string& binary, int start, int end) {
    if (start == end) {
        return true;
    }
    
    int mid = start + (end - start) / 2;
    int left = start + (mid - 1 - start) / 2;
    int right = mid + 1 + (end - (mid + 1)) / 2;
    if (binary[mid] == '0' && (binary[left] == '1' || binary[right] == '1')) {
        return false;
    }
    
    return is_valid(binary, start, mid - 1) && is_valid(binary, mid + 1, end);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (long long num : numbers) {
        string binary = "";
        long long temp = num;
        if (temp == 0) {
            binary = "0";
        }
        
        while (temp > 0) {
            binary += to_string(temp % 2);
            temp /= 2;
        }
        reverse(binary.begin(), binary.end());
        
        int height = binary.length();
        int tree = 1;
        int full = 1;
        while (full < height) {
            tree++;
            full = pow(2, tree) - 1;
        }
        
        string padded = string(full - height, '0') + binary;
        
        if (is_valid(padded, 0, padded.length() - 1)) {
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }
    return answer;
}