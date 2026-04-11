#include <iostream>
#include <deque>
#include <set>
using namespace std;
using pii = pair<int, int>;

int N, M, T;
int nums[51][51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> nums[i][j];
        }
    }

    for (int turn = 0; turn < T; turn++) {
        int x, d, k;
        cin >> x >> d >> k;

        for (int i = 1; i <= N; i++) {
            if (i % x == 0) {
                deque<int> list(nums[i] + 1, nums[i] + M + 1);

                int cnt = 0;
                if (d) {
                    while (cnt++ < k) {
                        int front = list.front(); list.pop_front();
                        list.push_back(front);
                    }
                }
                else {
                    while (cnt++ < k) {
                        int back = list.back(); list.pop_back();
                        list.push_front(back);
                    }
                }

                for (int j = 1; j <= M; j++) {
                    nums[i][j] = list[j - 1];
                }
            }
        }

        set<pii> will_erase;
        for (int i = 1; i < N; i++) {
            for (int j = 1; j <= M; j++) {
                if (nums[i][j] == 0) continue;
                if (nums[i][j] == nums[i + 1][j]) {
                    will_erase.insert({i, j});
                    will_erase.insert({i + 1, j});
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j < M; j++) {
                if (nums[i][j] == 0) continue;
                if (nums[i][j] == nums[i][j + 1]) {
                    will_erase.insert({i, j});
                    will_erase.insert({i, j + 1});
                }
            }
            if (nums[i][1] != 0 && nums[i][1] == nums[i][M]) {
                will_erase.insert({i, 1});
                will_erase.insert({i, M});
            }
        }

        if (will_erase.size() == 0) {
            int sum = 0, exist_num = N * M;
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (nums[i][j] == 0) {
                        exist_num--;
                        continue;
                    }
                    sum += nums[i][j];
                }
            }

            if (exist_num > 0) {
                double average = (double)sum / exist_num;
                for (int i = 1; i <= N; i++) {
                    for (int j = 1; j <= M; j++) {
                        if (nums[i][j] == 0) continue;
                        if ((double)nums[i][j] < average) nums[i][j]++;
                        else if ((double)nums[i][j] > average) nums[i][j]--;
                    }
                }
            }
        } else {
            for (auto [i, j] : will_erase) {
                nums[i][j] = 0;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            sum += nums[i][j];
        }
    }

    cout << sum << '\n';

    return 0;
}