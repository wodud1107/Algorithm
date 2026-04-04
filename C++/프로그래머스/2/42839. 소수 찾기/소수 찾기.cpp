#include <string>
#include <vector>
#include <set>

using namespace std;

int answer = 0;
int length = 0;
set<int> primes;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void dfs(int num, string& numbers, vector<bool>& visited) {
    if (is_prime(num)) {
        primes.insert(num);
    }
    
    for (int i = 0; i < length; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(num * 10 + (numbers[i] - '0'), numbers, visited); 
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    length = numbers.size();
    
    for (int i = 0; i < length; i++) {
        vector<bool> visited(length, false);
        visited[i] = true;
        dfs((numbers[i] - '0'), numbers, visited);
    }
    
    answer = primes.size();
    return answer;
}