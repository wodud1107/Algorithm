#include <iostream>
using namespace std;

int N;

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }

    return true;
}

void dfs(int num, int size) {
    if (size == N) {
        if (is_prime(num)) cout << num << '\n';
        return;
    }

    int odd[5] = { 1, 3, 5, 7, 9 };

    for (int o : odd) {
        int next = num * 10 + o;
        if (!is_prime(next)) continue;
        dfs(next, size + 1);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);

    return 0;
}