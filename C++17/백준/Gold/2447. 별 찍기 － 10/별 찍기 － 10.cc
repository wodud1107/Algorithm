#include <iostream>
#include <vector>
using namespace std;

vector<string> solve(int length);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> star = solve(N);

    for (string& s : star) cout << s << '\n';

    return 0;
}

vector<string> solve(int length){
    if (length == 3) return {
        "***", // 0
        "* *", // 1
        "***" // 2
    };

    vector<string> prev = solve(length / 3);
    vector<string> result;

    for (int i = 0; i < length; i++){
        string line;
        // top & bottom
        if (i < length / 3 || i >= 2 * (length / 3)){
            for (int j = 0; j < 3; j++){
                line += prev[i % (length / 3)];
            }
        } else { // middle
            line += prev[i % (length / 3)];
            line += string((length / 3), ' ');
            line += prev[i % (length / 3)];
        }
        result.push_back(line);
    }

    return result;
}