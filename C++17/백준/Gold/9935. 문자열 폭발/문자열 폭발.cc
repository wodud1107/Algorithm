#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str, bomb;
    cin >> str >> bomb;
    
    string result;
    int bomb_size = bomb.size();
    for (char c : str) {
        result += c;

        if (result.size() >= bomb_size) {
            bool same = true;
            for (int i = 0; i < bomb_size; i++) {
                if (result[result.size() - bomb_size + i] != bomb[i]) {
                    same = false;
                    break;
                }
            }

            if (same) {
                for (int i = 0; i < bomb_size; i++) {
                    result.pop_back();
                }
            }
        }
    }

    if (result.empty()) cout << "FRULA";
    else cout << result;
    
    return 0;
}