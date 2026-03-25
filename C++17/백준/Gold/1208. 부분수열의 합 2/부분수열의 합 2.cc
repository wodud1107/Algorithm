#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get_subset_sums(const vector<int>& arr, int start, int end) {
    vector<int> sums = { 0 };
    for (int i = start; i < end; i++) {
        int current_size = sums.size();
        for (int j = 0; j < current_size; j++) {
            sums.push_back(sums[j] + arr[i]);
        }
    }
    return sums;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> l_sums = get_subset_sums(arr, 0, N / 2);
    vector<int> r_sums = get_subset_sums(arr, N / 2, N);
    sort(l_sums.begin(), l_sums.end());
    sort(r_sums.begin(), r_sums.end());

    int l_ptr = 0;
    int r_ptr = r_sums.size() - 1;
    long long answer = 0;
    while (l_ptr < l_sums.size() && r_ptr >= 0) {
        int l = l_sums[l_ptr];
        int r = r_sums[r_ptr];
        int curr_sum = l + r;
        
        if (curr_sum == S) {
            long long l_cnt = 0;
            long long r_cnt = 0;

            while (l_ptr < l_sums.size() && l_sums[l_ptr] == l) {
                l_cnt++;
                l_ptr++;
            }

            while (r_ptr >= 0 && r_sums[r_ptr] == r) {
                r_cnt++;
                r_ptr--;
            }
            answer += (l_cnt * r_cnt);
        }
        else if (curr_sum < S) l_ptr++;
        else r_ptr--;
    }

    if (S == 0) answer -= 1;
    cout << answer;

    return 0;
}