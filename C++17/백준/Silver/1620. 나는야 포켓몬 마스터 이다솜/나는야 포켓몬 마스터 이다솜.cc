#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<int, string> poketmon;
    unordered_map<string, int> number;
    for (int i = 1; i <= N; i++){
        string name;
        cin >> name;

        poketmon[i] = name;
        number[name] = i;
    }

    while (M--){
        string input;
        cin >> input;

        if (isdigit(input[0])){
            int num = stoi(input);
            cout << poketmon[num] << '\n';
        } else {
            cout << number[input] << '\n';
        }
    }
    
    return 0;
}