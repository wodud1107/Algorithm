#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int arr[41];
int l_sums[1050000];
int r_sums[1050000];

void get_subset_sums(int start, int end, int* out_sums, int& out_size) {
    out_sums[0] = 0;
    out_size = 1;

    for (int i = start; i < end; i++) {
        int current_size = out_size;
        for (int j = 0; j < current_size; j++) {
            out_sums[out_size++] = out_sums[j] + arr[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int l_size = 0, r_size = 0;
    int mid = N / 2;
    get_subset_sums(0, mid, l_sums, l_size);
    get_subset_sums(mid, N, r_sums, r_size);
    sort(l_sums, l_sums + l_size);
    sort(r_sums, r_sums + r_size);

    int l_ptr = 0;
    int r_ptr = r_size - 1;
    long long answer = 0;
    while (l_ptr < l_size && r_ptr >= 0) {
        int l = l_sums[l_ptr];
        int r = r_sums[r_ptr];
        int curr_sum = l + r;
        
        if (curr_sum == S) {
            long long l_cnt = 0;
            long long r_cnt = 0;

            while (l_ptr < l_size && l_sums[l_ptr] == l) {
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