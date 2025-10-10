#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

string convert_to_k_base(int n, int k) {
    if (n == 0) return "0";
    
    string result = "";
    while (n > 0) {
        result += to_string(n % k);
        n /= k;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

bool is_prime(long long num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (long long i = 5; i * i <= num; i++) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string k_base = convert_to_k_base(n, k);
    
    stringstream ss(k_base);
    string segment;
    
    while (getline(ss, segment, '0')) {
        if (segment.empty()) {
            continue;
        }
        long long num = stoll(segment);
        if (is_prime(num)) {
            answer++;
        }
    }
    
    return answer;
}