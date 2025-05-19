#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string opstr;
    cin >> opstr;

    vector<int> nums;
    vector<char> operators;

    string n = "";
    for (char c : opstr){
        if (c == '+' || c == '-'){
            nums.push_back(stoi(n));
            operators.push_back(c);
            n = "";
        } else {
            n += c;
        }
    }
    nums.push_back(stoi(n));

    int answer = nums[0];
    bool sub = false;
    for (int i = 0; i < operators.size(); i++){
        if (operators[i] == '-'){
            sub = true;
        }

        if (sub){
            answer -= nums[i + 1];
        } else {
            answer += nums[i + 1];
        }
    }

    cout << answer << '\n';

    return 0;
}